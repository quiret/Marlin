/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Sanguinololu board pin assignments
 * Schematic (0.1): https://green-candy.osdn.jp/external/MarlinFW/board_schematics/Sanguinololu%20v0.1/schematic.png
 * Origin (0.1): https://github.com/mosfet/Sanguinololu/blob/master/rev0.1/sanguinololu.sch
 * Schematic (0.6): https://green-candy.osdn.jp/external/MarlinFW/board_schematics/Sanguinololu%20v0.6/schematic.jpg
 * Origin (0.6): https://github.com/mosfet/Sanguinololu/blob/master/rev0.6/images/schematic.jpg
 * Schematic (0.7): https://green-candy.osdn.jp/external/MarlinFW/board_schematics/Sanguinololu%20v0.7/schematic.jpg
 * Origin (0.7): https://github.com/mosfet/Sanguinololu/blob/master/rev0.7/images/schematic.jpg
 * Schematic (1.0): https://green-candy.osdn.jp/external/MarlinFW/board_schematics/Sanguinololu%20v1.0/Sanguinololu-schematic.jpg
 * Origin (1.0): https://reprap.org/wiki/File:Sanguinololu-schematic.jpg
 * Schematic (1.1): https://green-candy.osdn.jp/external/MarlinFW/board_schematics/Sanguinololu%20v1.1/schematic.png
 * Origin (1.1): https://github.com/mosfet/Sanguinololu/blob/master/rev1.1/sanguinololu.sch
 */

/**
 * Rev B    26 DEC 2016
 *
 * 1) added pointer to a current Arduino IDE extension
 * 2) added support for M3, M4 & M5 spindle control commands
 * 3) added case light pin definition
 */

/**
 * A useable Arduino IDE extension (board manager) can be found at
 * https://github.com/Lauszus/Sanguino
 *
 * This extension has been tested on Arduino 1.6.12 & 1.8.0
 *
 * Here's the JSON path:
 * https://raw.githubusercontent.com/Lauszus/Sanguino/master/package_lauszus_sanguino_index.json
 *
 * When installing select 1.0.2
 *
 * Installation instructions can be found at https://learn.sparkfun.com/pages/CustomBoardsArduino
 * Just use the above JSON URL instead of Sparkfun's JSON.
 *
 * Once installed select the Sanguino board and then select the CPU.
 */

#define ALLOW_MEGA644P
#include "env_validate.h"

#ifndef BOARD_INFO_NAME
  #define BOARD_INFO_NAME "Sanguinololu <1.2"
#endif

#ifndef AVR_CHIPOSCILLATOR_FREQ
  #define AVR_CHIPOSCILLATOR_FREQ 16000000
#endif

//
// Limit Switches
//
#define X_STOP_PIN                         PinC2
#define Y_STOP_PIN                         PinC3
#define Z_STOP_PIN                         PinC4

//
// Steppers
//
#define X_STEP_PIN                         PinD7
#define X_DIR_PIN                          PinC5

#define Y_STEP_PIN                         PinC6
#define Y_DIR_PIN                          PinC7

#define Z_STEP_PIN                         PinB3
#define Z_DIR_PIN                          PinB2

#define E0_STEP_PIN                        PinB1
#define E0_DIR_PIN                         PinB0

//
// Temperature Sensors
//
#define TEMP_0_PIN                         PinB7  // Analog Input (pin 33 extruder)
#define TEMP_BED_PIN                       PinB6  // Analog Input (pin 34 bed)

//
// Heaters / Fans
//
#define HEATER_0_PIN                       PinD5  // (extruder)

#ifndef FAN_PIN
  #define FAN_PIN                          PinB4  // Works for Panelolu2 too
#endif

#if DISABLED(SANGUINOLOLU_V_1_2)
  #define HEATER_BED_PIN                   PinD6  // (bed)
  #define X_ENABLE_PIN                     PinB4
  #define Y_ENABLE_PIN                     PinB4
  #ifndef Z_ENABLE_PIN
    #define Z_ENABLE_PIN                   PinB4
  #endif
  #define E0_ENABLE_PIN                    PinB4
#endif

//
// Misc. Functions
//

/**
 * In some versions of the Sanguino libraries the pin
 * definitions are wrong, with SDSS = 24 and LED_PIN = 28 (Melzi).
 * If you encounter issues with these pins, upgrade your
 * Sanguino libraries! See #368.
 */
//#define SDSS                             PinA7
#define SDSS                               PinA0

#if IS_MELZI
  #define LED_PIN                          PinA4
#elif MB(STB_11)
  #define LCD_BACKLIGHT_PIN                PinC1  // LCD backlight LED
#endif

#if !HAS_CUTTER && ENABLED(SANGUINOLOLU_V_1_2) && !BOTH(HAS_WIRED_LCD, IS_NEWPANEL)// try to use IO Header
  #define CASE_LIGHT_PIN                   PinB4  // Hardware PWM  - see if IO Header is available
#endif

/**
 * Sanguinololu 1.4 AUX pins:
 *
 *           PWM  TX1  RX1  SDA  SCL
 *  12V  5V  D12  D11  D10  D17  D16
 *  GND GND  D31  D30  D29  D28  D27
 *            A4   A3   A2   A1   A0
 */

//
// LCD / Controller
//
#if HAS_WIRED_LCD && DISABLED(LCD_PINS_DEFINED)

  #define SD_DETECT_PIN                       -1

  #if HAS_MARLINUI_U8GLIB

    #if ENABLED(LCD_FOR_MELZI)

      #define LCD_PINS_RS                  PinC1
      #define LCD_PINS_ENABLE              PinC0
      #define LCD_PINS_D4                  PinD3
      #define KILL_PIN                     PinD2
      #define BEEPER_PIN                   PinA4

    #elif IS_U8GLIB_ST7920                        // SPI GLCD 12864 ST7920 ( like [www.digole.com] ) For Melzi V2.0

      #if IS_MELZI
        #define LCD_PINS_RS                PinA1  // CS chip select /SS chip slave select
        #define LCD_PINS_ENABLE            PinA2  // SID (MOSI)
        #define LCD_PINS_D4                PinC1  // SCK (CLK) clock
        // Pin 27 is taken by LED_PIN, but Melzi LED does nothing with
        // Marlin so this can be used for BEEPER_PIN. You can use this pin
        // with M42 instead of BEEPER_PIN.
        #define BEEPER_PIN                 PinA4
      #else                                       // Sanguinololu >=1.3
        #define LCD_PINS_RS                PinB4
        #define LCD_PINS_ENABLE            PinC1
        #define LCD_PINS_D4                PinA1
        #define LCD_PINS_D5                PinA2
        #define LCD_PINS_D6                PinA3
        #define LCD_PINS_D7                PinA4
      #endif

    #else

      #define DOGLCD_A0                    PinA1

      #if ENABLED(MAKRPANEL)

        #define BEEPER_PIN                 PinA2
        #define DOGLCD_CS                  PinC1
        #define LCD_BACKLIGHT_PIN          PinA3  // PA3

      #elif IS_MELZI

        #define BEEPER_PIN                 PinA4
        #define DOGLCD_CS                  PinA3

      #else                                       // !MAKRPANEL

        #define DOGLCD_CS                  PinA2

      #endif

    #endif

    //#define LCD_SCREEN_ROTATE              180  // 0, 90, 180, 270

  #elif ENABLED(ZONESTAR_LCD)                     // For the Tronxy Melzi boards

    #define LCD_PINS_RS                    PinA3
    #define LCD_PINS_ENABLE                PinA2
    #define LCD_PINS_D4                    PinD2
    #define LCD_PINS_D5                    PinD3
    #define LCD_PINS_D6                    PinC0
    #define LCD_PINS_D7                    PinC1

  #else

    #define LCD_PINS_RS                    PinB4
    #define LCD_PINS_ENABLE                PinC1
    #define LCD_PINS_D4                    PinA1
    #define LCD_PINS_D5                    PinA2
    #define LCD_PINS_D6                    PinA3
    #define LCD_PINS_D7                    PinA4

  #endif

  #if ENABLED(LCD_FOR_MELZI)

    #define BTN_ENC                        PinA3
    #define BTN_EN1                        PinA2
    #define BTN_EN2                        PinA1

  #elif ENABLED(ZONESTAR_LCD)                     // For the Tronxy Melzi boards

    #define ADC_KEYPAD_PIN                 PinB1
    #define BTN_EN1                           -1
    #define BTN_EN2                           -1

  #elif ENABLED(LCD_I2C_PANELOLU2)

    #if IS_MELZI
      #define BTN_ENC                      PinA2
      #ifndef LCD_SDSS
        #define LCD_SDSS                   PinA1  // Panelolu2 SD card reader rather than the Melzi
      #endif
    #else
      #define BTN_ENC                      PinA1
    #endif

  #else                                           // !LCD_FOR_MELZI && !ZONESTAR_LCD && !LCD_I2C_PANELOLU2

    #define BTN_ENC                        PinC0
    #ifndef LCD_SDSS
      #define LCD_SDSS                     PinA3  // Smart Controller SD card reader rather than the Melzi
    #endif

  #endif

  #if IS_NEWPANEL && !defined(BTN_EN1)
    #define BTN_EN1                        PinD3
    #define BTN_EN2                        PinD2
  #endif

#endif // HAS_WIRED_LCD

//
// M3/M4/M5 - Spindle/Laser Control
//
#if HAS_CUTTER
  #if !MB(AZTEEG_X1) && ENABLED(SANGUINOLOLU_V_1_2) && !BOTH(HAS_WIRED_LCD, IS_NEWPANEL)// try to use IO Header

    #define SPINDLE_LASER_ENA_PIN          PinD2  // Pullup or pulldown!
    #define SPINDLE_LASER_PWM_PIN          PinB4  // Hardware PWM
    #define SPINDLE_DIR_PIN                PinD3

  #elif !MB(MELZI)                                // use X stepper motor socket

    /**
     *  To control the spindle speed and have an LCD you must sacrifice
     *  the Extruder and pull some signals off the X stepper driver socket.
     *
     *  The following assumes:
     *   - The X stepper driver socket is empty
     *   - The extruder driver socket has a driver board plugged into it
     *   - The X stepper wires are attached the the extruder connector
     */

    /**
     *  Where to get the spindle signals
     *
     *      spindle signal          socket name       socket name
     *                                         -------
     *                               /ENABLE  O|     |O  VMOT
     *                                   MS1  O|     |O  GND
     *                                   MS2  O|     |O  2B
     *                                   MS3  O|     |O  2A
     *                                /RESET  O|     |O  1A
     *                                /SLEEP  O|     |O  1B
     *  SPINDLE_LASER_PWM_PIN           STEP  O|     |O  VDD
     *  SPINDLE_LASER_ENA_PIN         DIR  O|     |O  GND
     *                                         -------
     *
     *  Note: Socket names vary from vendor to vendor.
     */
    #undef X_DIR_PIN
    #undef X_ENABLE_PIN
    #undef X_STEP_PIN
    #define X_DIR_PIN                      PinB0
    #define X_ENABLE_PIN                   PinD6
    #define X_STEP_PIN                     PinB1
    #define SPINDLE_LASER_PWM_PIN          PinD7  // Hardware PWM
    #define SPINDLE_LASER_ENA_PIN          PinC5  // Pullup!
    #define SPINDLE_DIR_PIN                   -1  // No pin available on the socket for the direction pin
  #endif
#endif
