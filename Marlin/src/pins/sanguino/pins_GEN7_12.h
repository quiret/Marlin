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
 * Gen7 v1.1, v1.2, v1.3 pin assignments
 * Schematic (1.1): https://green-candy.osdn.jp/external/MarlinFW/board_schematics/Gen7%20v1.1/Gen7Board%20Schematic.pdf
 * Origin (1.1): https://github.com/Traumflug/Generation_7_Electronics/blob/release-1.1/release%20documents/Gen7Board%20Schematic.pdf
 * Schematic (1.2): https://green-candy.osdn.jp/external/MarlinFW/board_schematics/Gen7%20v1.2/Gen7Board%20Schematic.pdf
 * Origin (1.2): https://github.com/Traumflug/Generation_7_Electronics/blob/release-1.2/release%20documents/Gen7Board%20Schematic.pdf
 * Schematic (1.3): https://green-candy.osdn.jp/external/MarlinFW/board_schematics/Gen7%20v1.3/Gen7Board%20Schematic.pdf
 * Origin (1.3): https://github.com/Traumflug/Generation_7_Electronics/blob/release-1.3/release%20documents/Gen7Board%20Schematic.pdf
 * Schematic (1.3.1): https://green-candy.osdn.jp/external/MarlinFW/board_schematics/Gen7%20v1.3.1/Gen7Board%20Schematic.pdf
 * Origin (1.3.1): https://github.com/Traumflug/Generation_7_Electronics/blob/release-1.3.1/release%20documents/Gen7Board%20Schematic.pdf
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

#define ALLOW_MEGA644
#include "env_validate.h"

#ifndef BOARD_INFO_NAME
  #define BOARD_INFO_NAME "Gen7 v1.1 - v1.3"
#endif

#ifndef GEN7_VERSION
  #define GEN7_VERSION                        PinD4  // v1.x
#endif

#if defined(GEN7_VERSION) && GEN7_VERSION >= 13
  // Holy moly! Check the schematic! Ring the alarm bells!
  #define AVR_CHIPOSCILLATOR_FREQ 20000000
#else
  #define AVR_CHIPOSCILLATOR_FREQ 16000000
#endif

//
// Limit Switches
//
#define X_MIN_PIN                             PinB7
#define Y_MIN_PIN                             PinB5
#define Z_MIN_PIN                             PinB1
#define Z_MAX_PIN                             PinB0
#define Y_MAX_PIN                             PinB2
#define X_MAX_PIN                             PinB6

//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN                     PinB0
#endif

//
// Steppers
//
#define X_STEP_PIN                            PinC3
#define X_DIR_PIN                             PinC2
#define X_ENABLE_PIN                          PinA7

#define Y_STEP_PIN                            PinC7
#define Y_DIR_PIN                             PinC6
#define Y_ENABLE_PIN                          PinA7

#define Z_STEP_PIN                            PinA5
#define Z_DIR_PIN                             PinA6
#define Z_ENABLE_PIN                          PinA7

#define E0_STEP_PIN                           PinA3
#define E0_DIR_PIN                            PinA4
#define E0_ENABLE_PIN                         PinA7

//
// Temperature Sensors
//
#define TEMP_0_PIN                            PinB1  // Analog Input
#define TEMP_BED_PIN                          PinB2  // Analog Input

//
// Heaters / Fans
//
#define HEATER_0_PIN                          PinB4
#define HEATER_BED_PIN                        PinB3

#if !defined(FAN_PIN) && GEN7_VERSION < 13        // Gen7 v1.3 removed the fan pin
  #define FAN_PIN                             PinA0
#endif

//
// Misc. Functions
//
#define PS_ON_PIN                             PinD7

#if GEN7_VERSION < 13
  #define CASE_LIGHT_PIN                      PinC0  // Hardware PWM
#else                                             // Gen7 v1.3 removed the I2C connector & signals so need to get PWM off the PC power supply header
  #define CASE_LIGHT_PIN                      PinD7  // Hardware PWM
#endif

// All these generations of Gen7 supply thermistor power
// via PS_ON, so ignore bad thermistor readings
//#define BOGUS_TEMPERATURE_GRACE_PERIOD     2000

#define DEBUG_PIN                             PinB0

// RS485 pins
#define TX_ENABLE_PIN                         PinD4
#define RX_ENABLE_PIN                         PinD5

//
// M3/M4/M5 - Spindle/Laser Control
//
#define SPINDLE_LASER_ENA_PIN                 PinD2  // Pullup or pulldown!
#define SPINDLE_DIR_PIN                       PinD3
#if GEN7_VERSION < 13
  #define SPINDLE_LASER_PWM_PIN               PinC0  // Hardware PWM
#else                                             // Gen7 v1.3 removed the I2C connector & signals so need to get PWM off the PC power supply header
  #define SPINDLE_LASER_PWM_PIN               PinD7  // Hardware PWM
#endif
