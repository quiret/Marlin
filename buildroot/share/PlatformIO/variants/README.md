# Marlin Custom Variants

This folder contains Marlin custom variants for both generic and custom boards.

There are two ways that Marlin can specify a board variant:
- With the `board_build.variant = VARIANT_MAME` field, specifying the variant subfolder name.
- With the `board = board_name` field set to a custom board with a `build.variant` field.

## Variant File Naming

With the latest STM32 platform the full names of the `variant.h` and `variant.cpp` files are based on the name of the board. If the variant is based on a generic board definition, not a Marlin custom board, then `variant_generic.h`/`.cpp` should be used. Otherwise, the capitalized name of the `board` should be used.

| board | board file | variant | Variant Files |
|-------|------------|---------|---------------|
|`genericSTM32F103VE`|n/a|`MARLIN_F103Vx`|`variants/MARLIN_F103Vx/variant_generic.*`|
|`marlin_STM32F407ZE`|`marlin_STM32F407ZE.json`|`MARLIN_F407ZE`|`variants/MARLIN_F407ZE/variant_MARLIN_F407ZE.*`|

## Custom Boards

See the `buildroot/PlatformIO/boards` folder for Marlin custom boards.
