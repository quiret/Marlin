#
# common-dependencies.py
# Convenience script to check dependencies and add libs and sources for Marlin Enabled Features
#
import pioutil
if pioutil.is_pio_build():

    import subprocess,os,re,fnmatch,glob
    srcfilepattern = re.compile(r".*[.](cpp|c)$")
    marlinbasedir = os.path.join(os.getcwd(), "Marlin/")
    Import("env")

    from platformio.package.meta import PackageSpec
    from platformio.project.config import ProjectConfig

    verbose = 0
    FEATURE_CONFIG = {}

    def validate_pio():
        PIO_VERSION_MIN = (6, 0, 1)
        try:
            from platformio import VERSION as PIO_VERSION
            weights = (1000, 100, 1)
            version_min = sum([x[0] * float(re.sub(r'[^0-9]', '.', str(x[1]))) for x in zip(weights, PIO_VERSION_MIN)])
            version_cur = sum([x[0] * float(re.sub(r'[^0-9]', '.', str(x[1]))) for x in zip(weights, PIO_VERSION)])
            if version_cur < version_min:
                print()
                print("**************************************************")
                print("******      An update to PlatformIO is      ******")
                print("******  required to build Marlin Firmware.  ******")
                print("******                                      ******")
                print("******      Minimum version: ", PIO_VERSION_MIN, "    ******")
                print("******      Current Version: ", PIO_VERSION, "    ******")
                print("******                                      ******")
                print("******   Update PlatformIO and try again.   ******")
                print("**************************************************")
                print()
                exit(1)
        except SystemExit:
            exit(1)
        except:
            print("Can't detect PlatformIO Version")

    def blab(str,level=1):
        if verbose >= level:
            print("[deps] %s" % str)

    def add_to_feat_cnf(feature, flines):

        try:
            feat = FEATURE_CONFIG[feature]
        except:
            FEATURE_CONFIG[feature] = {}

        # Get a reference to the FEATURE_CONFIG under construction
        feat = FEATURE_CONFIG[feature]

        # Split up passed lines on commas or newlines and iterate
        # Add common options to the features config under construction
        # For lib_deps replace a previous instance of the same library
        atoms = re.sub(r',\s*', '\n', flines).strip().split('\n')
        for line in atoms:
            parts = line.split('=')
            name = parts.pop(0)
            if name in ['build_flags', 'extra_scripts', 'src_filter', 'lib_ignore']:
                feat[name] = '='.join(parts)
                blab("[%s] %s=%s" % (feature, name, feat[name]), 3)
            else:
                for dep in re.split(r',\s*', line):
                    lib_name = re.sub(r'@([~^]|[<>]=?)?[\d.]+', '', dep.strip()).split('=').pop(0)
                    lib_re = re.compile('(?!^' + lib_name + '\\b)')
                    feat['lib_deps'] = list(filter(lib_re.match, feat['lib_deps'])) + [dep]
                    blab("[%s] lib_deps = %s" % (feature, dep), 3)

    def load_features():
        blab("========== Gather [features] entries...")
        for key in ProjectConfig().items('features'):
            feature = key[0].upper()
            if not feature in FEATURE_CONFIG:
                FEATURE_CONFIG[feature] = { 'lib_deps': [] }
            add_to_feat_cnf(feature, key[1])

        # Add options matching custom_marlin.MY_OPTION to the pile
        blab("========== Gather custom_marlin entries...")
        for n in env.GetProjectOptions():
            key = n[0]
            mat = re.match(r'custom_marlin\.(.+)', key)
            if mat:
                try:
                    val = env.GetProjectOption(key)
                except:
                    val = None
                if val:
                    opt = mat[1].upper()
                    blab("%s.custom_marlin.%s = '%s'" % ( env['PIOENV'], opt, val ))
                    add_to_feat_cnf(opt, val)

    def get_all_known_libs():
        known_libs = []
        for feature in FEATURE_CONFIG:
            feat = FEATURE_CONFIG[feature]
            if not 'lib_deps' in feat:
                continue
            for dep in feat['lib_deps']:
                known_libs.append(PackageSpec(dep).name)
        return known_libs

    def get_all_env_libs():
        env_libs = []
        lib_deps = env.GetProjectOption('lib_deps')
        for dep in lib_deps:
            env_libs.append(PackageSpec(dep).name)
        return env_libs

    def set_env_field(field, value):
        proj = env.GetProjectConfig()
        proj.set("env:" + env['PIOENV'], field, value)

    # All unused libs should be ignored so that if a library
    # exists in .pio/lib_deps it will not break compilation.
    def force_ignore_unused_libs():
        env_libs = get_all_env_libs()
        known_libs = get_all_known_libs()
        diff = (list(set(known_libs) - set(env_libs)))
        lib_ignore = env.GetProjectOption('lib_ignore') + diff
        blab("Ignore libraries: %s" % lib_ignore)
        set_env_field('lib_ignore', lib_ignore)

    def apply_features_config():
        load_features()
        blab("========== Apply enabled features...")
        build_filters = ' '.join(env.GetProjectOption('src_filter'))
        for feature in FEATURE_CONFIG:
            if not env.MarlinHas(feature):
                continue

            feat = FEATURE_CONFIG[feature]

            if 'lib_deps' in feat and len(feat['lib_deps']):
                blab("========== Adding lib_deps for %s... " % feature, 2)

                # feat to add
                deps_to_add = {}
                for dep in feat['lib_deps']:
                    deps_to_add[PackageSpec(dep).name] = dep
                    blab("==================== %s... " % dep, 2)

                # Does the env already have the dependency?
                deps = env.GetProjectOption('lib_deps')
                for dep in deps:
                    name = PackageSpec(dep).name
                    if name in deps_to_add:
                        del deps_to_add[name]

                # Are there any libraries that should be ignored?
                lib_ignore = env.GetProjectOption('lib_ignore')
                for dep in deps:
                    name = PackageSpec(dep).name
                    if name in deps_to_add:
                        del deps_to_add[name]

                # Is there anything left?
                if len(deps_to_add) > 0:
                    # Only add the missing dependencies
                    set_env_field('lib_deps', deps + list(deps_to_add.values()))

            if 'build_flags' in feat:
                f = feat['build_flags']
                blab("========== Adding build_flags for %s: %s" % (feature, f), 2)
                new_flags = env.GetProjectOption('build_flags') + [ f ]
                env.Replace(BUILD_FLAGS=new_flags)

            if 'extra_scripts' in feat:
                blab("Running extra_scripts for %s... " % feature, 2)
                env.SConscript(feat['extra_scripts'], exports="env")

            if 'src_filter' in feat:
                blab("========== Adding build_src_filter for %s... " % feature, 2)
                build_filters = build_filters + ' ' + feat['src_filter']
                # Just append the filter in the order that the build environment specifies.
                # Important here is the order of entries in the "features.ini" file.

            if 'lib_ignore' in feat:
                blab("========== Adding lib_ignore for %s... " % feature, 2)
                lib_ignore = env.GetProjectOption('lib_ignore') + [feat['lib_ignore']]
                set_env_field('lib_ignore', lib_ignore)

        src_filter = ""
        if True:
            # Build the actual equivalent build_src_filter list based on the inclusions by the features.
            # PlatformIO itself is NOT smart enough to do this! Maybe in the future it may become smart...
            cur_srcs = set()
            # first we need to remove the references to the same folder
            my_srcs = re.findall(r'([+-]<.*?>)', build_filters)
            def printpathdbg(x):
                #print(x)
                return
            for d in my_srcs:
                # gonna assume normalized relative paths here.
                plain = d[2:-1]
                if d[0] == '+':
                    def addentry(fullpath, info=None):
                        relp = os.path.relpath(fullpath, marlinbasedir)
                        if srcfilepattern.match(relp):
                            if info:
                                printpathdbg( "Added src file " + relp + " (" + str(info) + ")" )
                            else:
                                printpathdbg( "Added src file " + relp )
                            cur_srcs.add(relp)
                    # Special rule by PlatformIO: if a direct folder is specified then add all files
                    # inside of that folder
                    fullplain = os.path.join(marlinbasedir, plain)
                    if os.path.isdir(fullplain):
                        printpathdbg( "Directory content addition for " + plain )
                        gpattern = os.path.join(fullplain, "**")
                        for fname in glob.glob(gpattern, recursive=True):
                            addentry(fname, "dca")
                    else:
                        # Add all the things from the pattern by GLOB.
                        def srepl(matchi):
                            g0 = matchi.group(0)
                            return r"**" + g0[1:]
                        gpattern = re.sub(r'[*]($|[^*])', srepl, plain)
                        gpattern = os.path.join(marlinbasedir, gpattern)

                        for fname in glob.glob(gpattern, recursive=True):
                            addentry(fname)
                else:
                    # Special rule by PlatformIO: if a direct folder is specified then remove all files
                    # from it.
                    def onremove(relp, info=None):
                        if info:
                            printpathdbg( "Removed src file " + relp + " (" + str(info) + ")" )
                        else:
                            printpathdbg( "Removed src file " + relp )
                    fullplain = os.path.join(marlinbasedir, plain)
                    if os.path.isdir(fullplain):
                        printpathdbg( "Directory content removal for " + plain )
                        def filt(x):
                            common = os.path.commonpath([plain, x])
                            if not common == os.path.normpath(plain):
                                return True
                            onremove(x, "dcr")
                            return False
                        cur_srcs = set(filter(filt, cur_srcs))
                    else:
                        # Remove source entries that match pattern.
                        def filt(x):
                            if not fnmatch.fnmatch(x, plain):
                                return True
                            onremove(x)
                            return False
                        cur_srcs = set(filter(filt, cur_srcs))
            # Transform the set into a string.
            for x in cur_srcs:
                if len(src_filter) > 0:
                    src_filter += ' '
                src_filter += "+<" + x + ">"

            #print( "Final: " + src_filter )
        else:
            src_filter = build_filters

        # Tell it to PlatformIO.
        set_env_field('build_src_filter', [src_filter])
        env.Replace(SRC_FILTER=src_filter)

    #
    # Use the compiler to get a list of all enabled features
    #
    def load_marlin_features():
        if 'MARLIN_FEATURES' in env:
            return

        # Process defines
        from preprocessor import run_preprocessor
        define_list = run_preprocessor(env)
        marlin_features = {}
        for define in define_list:
            feature = define[8:].strip().decode().split(' ')
            feature, definition = feature[0], ' '.join(feature[1:])
            marlin_features[feature] = definition

        # Only build with the required font files, shortens build time.
        notofont_feat = "NOTOSANS"  # default
        if 'TFT_FONT' in marlin_features:
            notofont_feat = marlin_features["TFT_FONT"]

        if notofont_feat:
            marlin_features["TFT_FONT_" + notofont_feat] = "1"

        env['MARLIN_FEATURES'] = marlin_features

    #
    # Return True if a matching feature is enabled
    #
    def MarlinHas(env, feature):
        load_marlin_features()
        r = re.compile('^' + feature + '$')
        found = list(filter(r.match, env['MARLIN_FEATURES']))

        # Defines could still be 'false' or '0', so check
        some_on = False
        if len(found):
            for f in found:
                val = env['MARLIN_FEATURES'][f]
                if val in [ '', '1', 'true' ]:
                    some_on = True
                elif val in env['MARLIN_FEATURES']:
                    some_on = env.MarlinHas(val)

        #print( feature + " is " + str(some_on) )

        return some_on

    validate_pio()

    try:
        verbose = int(env.GetProjectOption('custom_verbose'))
    except:
        pass

    #
    # Add a method for other PIO scripts to query enabled features
    #
    env.AddMethod(MarlinHas)

    #
    # Add dependencies for enabled Marlin features
    #
    apply_features_config()
    force_ignore_unused_libs()

    #print(env.Dump())

    from signature import compute_build_signature
    compute_build_signature(env)
