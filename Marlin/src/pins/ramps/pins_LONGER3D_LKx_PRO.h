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
 * Longer3D LK1/LK4/LK5 Pro board pin assignments
 * ATmega2560
 */

#define REQUIRE_MEGA2560
#include "env_validate.h"

#if HAS_MULTI_HOTEND || E_STEPPERS > 1
  #error "Longer3D LGT KIT V1.0 only supports 1 hotend / E stepper."
#endif

#if SERIAL_PORT == 1 || SERIAL_PORT_2 == 1 || SERIAL_PORT_3 == 1
  #warning "Serial 1 is originally reserved for DGUS LCD."
#endif
#if SERIAL_PORT == 2 || SERIAL_PORT_2 == 2 || SERIAL_PORT_3 == 2 || LCD_SERIAL_PORT == 2
  #warning "Serial 2 has no connector. Hardware changes may be required to use it."
#endif
#if SERIAL_PORT == 3 || SERIAL_PORT_2 == 3 || SERIAL_PORT_3 == 3 || LCD_SERIAL_PORT == 3
  #warning "Serial 3 is originally reserved for Y limit switches. Hardware changes are required to use it."
  #define Y_STOP_PIN                       PinC0
  #if MB(LONGER3D_LKx_PRO)
    #define Z_STOP_PIN                     PinC2
  #endif
#endif

#define BOARD_INFO_NAME "LGT KIT V1.0"
#if ENABLED(LONGER_LK5)
  #define DEFAULT_MACHINE_NAME "LONGER LK5"
#else
  #define DEFAULT_MACHINE_NAME "LONGER 3D Printer"
#endif

//
// Servos
//
#if MB(LONGER3D_LKx_PRO)
  #define SERVO0_PIN                       PinH4
#endif
#define SERVO1_PIN                            -1
#define SERVO2_PIN                            -1
#define SERVO3_PIN                            -1

//
// Limit Switches
//
#if ENABLED(LONGER_LK5)
  #define X_MIN_PIN                        PinE5
  #define X_MAX_PIN                        PinE4
#else
  #define X_STOP_PIN                       PinE5
#endif

#if !ANY_PIN(Y_MIN, Y_MAX, Y_STOP)
  #if ENABLED(LONGER_LK5)
    #define Y_STOP_PIN                     PinJ1
  #else
    #define Y_MIN_PIN                      PinJ1
    #define Y_MAX_PIN                      PinJ0
  #endif
#endif

#if !ANY_PIN(Z_MIN, Z_MAX, Z_STOP)
  #if MB(LONGER3D_LKx_PRO)
    #define Z_MIN_PIN                      PinC2
  #else
    #define Z_MIN_PIN                      PinB5
  #endif
  #define Z_MAX_PIN                        PinC0
#endif

//
// Z Probe (when not Z_MIN_PIN)
//
#define Z_MIN_PROBE_PIN                       -1

//
// Steppers - No E1 pins
//
#define E1_STEP_PIN                           -1
#define E1_DIR_PIN                            -1
#define E1_ENABLE_PIN                         -1
#define E1_CS_PIN                             -1

//
// Temperature Sensors
//
#define TEMP_1_PIN                            -1

//
// Průša i3 MK2 Multiplexer Support
//
#if HAS_PRUSA_MMU1
  #define E_MUX2_PIN                          -1
#endif

//
// Misc. Functions
//
#define SD_DETECT_PIN                      PinL0
#define FIL_RUNOUT_PIN                     PinE4

//          ------------------        ----------------        ---------------        -------------
//    Aux-1 | D19 D18 GND 5V |    J21 | D4 D5 D6 GND |    J17 | D11 GND 24V |    J18 | D7 GND 5V |
//          ------------------        ----------------        ---------------        -------------

#if BOTH(CR10_STOCKDISPLAY, LONGER_LK5)
  /**           CR-10 Stock Display
   *                  ------
   *             GND | 9 10 | 5V
   * LCD_PINS_RS D5  | 7  8 | D4  LCD_PINS_ENABLE
   *     BTN_EN2 D19 | 5  6   D6  LCD_PINS_D4
   *     BTN_EN1 D18 | 3  4 | GND
   *  BEEPER_PIN D11 | 1  2 | D15 BTN_ENC
   *                  ------
   *      Connected via provided custom cable to:
   *      Aux-1, J21, J17 and Y-Max.
   */
  #define LCD_PINS_RS                         PinE3
  #define LCD_PINS_ENABLE                     PinG5
  #define LCD_PINS_D4                         PinH3
  #define BTN_EN1                             PinD3
  #define BTN_EN2                             PinD2
  #define BTN_ENC                             PinJ0
  #define BEEPER_PIN                          PinB5

  #define SDCARD_CONNECTION              ONBOARD

  #define LCD_PINS_DEFINED
#endif

//
// Other RAMPS 1.3 pins
//
#include "pins_RAMPS_13.h" // ... pins_RAMPS.h
