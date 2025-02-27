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
 * Einsy-Rambo pin assignments
 * Schematic: https://green-candy.osdn.jp/external/MarlinFW/board_schematics/Einsy-Rambo/Schematic%20Prints_Einsy%20Rambo_1.1a.PDF
 * Origin: https://github.com/ultimachine/Einsy-Rambo/blob/1.1a/board/Project%20Outputs/Schematic%20Prints_Einsy%20Rambo_1.1a.PDF
 */

#include "env_validate.h"

#define BOARD_INFO_NAME       "Einsy Rambo"
#define DEFAULT_MACHINE_NAME  "Prusa MK3"

#define AVR_CHIPOSCILLATOR_FREQ 16000000

//#define MK3_FAN_PINS

//
// TMC2130 Configuration_adv defaults for EinsyRambo
//
#if !AXIS_DRIVER_TYPE_X(TMC2130) || !AXIS_DRIVER_TYPE_Y(TMC2130) || !AXIS_DRIVER_TYPE_Z(TMC2130) || !AXIS_DRIVER_TYPE_E0(TMC2130)
  #error "You must set ([XYZ]|E0)_DRIVER_TYPE to TMC2130 in Configuration.h for EinsyRambo."
#endif

// TMC2130 Diag Pins (currently just for reference)
#define X_DIAG_PIN                            PinK2
#define Y_DIAG_PIN                            PinK7
#define Z_DIAG_PIN                            PinK6
#define E0_DIAG_PIN                           PinK3

//
// Limit Switches
//
// Only use Diag Pins when SENSORLESS_HOMING is enabled for the TMC2130 drivers.
// Otherwise use a physical endstop based configuration.
//
// SERVO0_PIN and Z_MIN_PIN configuration for BLTOUCH sensor when combined with SENSORLESS_HOMING.
//

#if DISABLED(SENSORLESS_HOMING)

  #define X_STOP_PIN                          PinB6
  #define Y_STOP_PIN                          PinB5
  #define Z_STOP_PIN                          PinB4

#else

  #define X_STOP_PIN                  X_DIAG_PIN
  #define Y_STOP_PIN                  Y_DIAG_PIN

  #if ENABLED(BLTOUCH)
    #define Z_STOP_PIN                        PinB5  // Y-MIN
    #define SERVO0_PIN                        PinB4  // Z-MIN
  #else
    #define Z_STOP_PIN                        PinB4
  #endif

#endif

//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN                     PinB4
#endif

//
// Filament Runout Sensor
//
#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN                      PinK0
#endif

//
// Steppers
//
#define X_STEP_PIN                            PinC0
#define X_DIR_PIN                             PinL0
#define X_ENABLE_PIN                          PinA7
#define X_CS_PIN                              PinG0

#define Y_STEP_PIN                            PinC1
#define Y_DIR_PIN                             PinL1
#define Y_ENABLE_PIN                          PinA6
#define Y_CS_PIN                              PinG2

#define Z_STEP_PIN                            PinC2
#define Z_DIR_PIN                             PinL2
#define Z_ENABLE_PIN                          PinA5
#define Z_CS_PIN                              PinK5

#define E0_STEP_PIN                           PinC3
#define E0_DIR_PIN                            PinL6
#define E0_ENABLE_PIN                         PinA4
#define E0_CS_PIN                             PinK4

//
// Temperature Sensors
//
#define TEMP_0_PIN                            PinE0  // Analog Input, Header J2
#define TEMP_1_PIN                            PinE1  // Analog Input, Header J3
// FATAL ERROR: TEMP_BOARD_PIN does not exist!
#define TEMP_BOARD_PIN                        91  // Onboard thermistor, 100k TDK NTCG104LH104JT1
#define TEMP_BED_PIN                          PinE4  // Analog Input, Header J6
#define TEMP_PROBE_PIN                        PinE5  // Analog Input, Header J15

//
// Heaters / Fans
//
#define HEATER_0_PIN                          PinE5
#define HEATER_BED_PIN                        PinG5

#ifndef FAN_PIN
  #ifdef MK3_FAN_PINS
    #define FAN_PIN                           PinH3
  #else
    #define FAN_PIN                           PinH5
  #endif
#endif

#ifndef FAN1_PIN
  #ifdef MK3_FAN_PINS
    #define FAN1_PIN                          -1
  #else
    #define FAN1_PIN                          PinH3
  #endif
#endif

/**
 *             ------                           ------                           ------
 *     84 PH2 | 1  2 | PH6  9          50 MISO | 1  2 | SCK  52          62 PK0 | 1  2 | PJ5 76
 *     61 PF7 | 3  4 | PD5 82          72  PJ2 | 3  4 | SDSS 77          20 SDA | 3  4 | GND
 *     59 PF5 | 5  6   PG4 70          14  TX3 | 5  6   MOSI 51          21 SCL | 5  6   RX2 16
 *     85 PH7 | 7  8 | PG3 71          15  RX3 | 7  8 | RESET               GND | 7  8 | TX2 17
 *        GND | 9 10 | 5V                  GND | 9 10 | PE3   5              5V | 9 10 | 5V
 *             ------                           ------                           ------
 *               P1                               P2                               P3
 */

#define EXP1_01_PIN                           PinH2
#define EXP1_02_PIN                           PinH6
#define EXP1_03_PIN                           PinF7
#define EXP1_04_PIN                           PinD5
#define EXP1_05_PIN                           PinF5
#define EXP1_06_PIN                           PinG4
#define EXP1_07_PIN                           PinH7
#define EXP1_08_PIN                           PinG3

#define EXP2_01_PIN                           PinB3
#define EXP2_02_PIN                           PinB1
#define EXP2_03_PIN                           PinJ2
#define EXP2_04_PIN                           PinJ6
#define EXP2_05_PIN                           PinJ1
#define EXP2_06_PIN                           PinB2
#define EXP2_07_PIN                           PinJ0
#define EXP2_08_PIN                           -1

//
// Misc. Functions
//
#define SDSS                         EXP2_04_PIN
#define LED_PIN                               PinB7

#ifndef CASE_LIGHT_PIN
  #define CASE_LIGHT_PIN             EXP1_02_PIN
#endif

//
// M3/M4/M5 - Spindle/Laser Control
//
// use P1 connector for spindle pins
#define SPINDLE_LASER_PWM_PIN        EXP1_02_PIN  // Hardware PWM
#define SPINDLE_LASER_ENA_PIN                 PinD3  // Pullup!
#define SPINDLE_DIR_PIN                       PinD2

//
// Průša i3 MK2 Multiplexer Support
//
#if HAS_PRUSA_MMU1
  #define E_MUX0_PIN                          PinH0
  #define E_MUX1_PIN                          PinH1
  #define E_MUX2_PIN                          PinE2  // 84 in MK2 Firmware, with BEEPER as 78
#endif

//
// LCD / Controller
//
#if HAS_WIRED_LCD || TOUCH_UI_ULTIPANEL

  #define KILL_PIN                            PinC5

  #if IS_ULTIPANEL || TOUCH_UI_ULTIPANEL

    #if ENABLED(CR10_STOCKDISPLAY)
      #define LCD_PINS_RS            EXP1_07_PIN
      #define LCD_PINS_ENABLE        EXP1_08_PIN
      #define LCD_PINS_D4            EXP1_06_PIN
      #define BTN_EN1                EXP1_03_PIN
      #define BTN_EN2                EXP1_05_PIN
    #else
      #define LCD_PINS_RS            EXP1_04_PIN
      #define LCD_PINS_ENABLE        EXP1_03_PIN
      #define LCD_PINS_D4            EXP1_05_PIN
      #define LCD_PINS_D5            EXP1_06_PIN
      #define LCD_PINS_D6            EXP1_07_PIN
      #define LCD_PINS_D7            EXP1_08_PIN
      #define BTN_EN1                EXP2_05_PIN
      #define BTN_EN2                EXP2_03_PIN

      #if ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)
        #define BTN_ENC_EN           LCD_PINS_D7  // Detect the presence of the encoder
      #endif

    #endif

    #define BTN_ENC                  EXP1_02_PIN  // P1
    #define BEEPER_PIN               EXP1_01_PIN  // P1
    #define SD_DETECT_PIN            EXP2_07_PIN

  #endif // IS_ULTIPANEL || TOUCH_UI_ULTIPANEL
#endif // HAS_WIRED_LCD

#if IS_U8GLIB_ST7920
  #define BOARD_ST7920_DELAY_1                 0
  #define BOARD_ST7920_DELAY_2               250
  #define BOARD_ST7920_DELAY_3                 0
#endif

#undef MK3_FAN_PINS
