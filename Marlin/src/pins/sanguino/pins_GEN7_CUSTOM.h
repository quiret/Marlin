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
 * Gen7 Alfons3 board pin assignments
 *
 * These Pins are assigned for the modified GEN7 Board from Alfons3.
 * Please review the pins and adjust them for your needs.
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

#define BOARD_INFO_NAME "Gen7 Custom"

// Just a wild guess because no schematics!
#define AVR_CHIPOSCILLATOR_FREQ 16000000

//
// Limit Switches
//
#define X_STOP_PIN                            PinB0
#define Y_STOP_PIN                            PinB1
#define Z_STOP_PIN                            PinB2

//
// Steppers
//
#define X_STEP_PIN                            PinC5  // different from standard GEN7
#define X_DIR_PIN                             PinC4  // different from standard GEN7
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
#define TEMP_0_PIN                            PinB2  // Analog Input
#define TEMP_BED_PIN                          PinB1  // Analog Input (pin 34 bed)

//
// Heaters
//
#define HEATER_0_PIN                          PinB4
#define HEATER_BED_PIN                        PinB3  // (bed)

//
// Misc. Functions
//
#define SDSS                                  PinA0  // SCL pin of I2C header || CS Pin for SD Card support
#define PS_ON_PIN                             PinC3

#ifndef CASE_LIGHT_PIN
  #define CASE_LIGHT_PIN                      PinD7  // Hardware PWM
#endif

// A pin for debugging
#define DEBUG_PIN                             -1

//
// LCD / Controller
//
#define BEEPER_PIN                            -1

// 4bit LCD Support
#define LCD_PINS_RS                           PinC2
#define LCD_PINS_ENABLE                       PinC1
#define LCD_PINS_D4                           PinC0
#define LCD_PINS_D5                           PinD7
#define LCD_PINS_D6                           PinD5
#define LCD_PINS_D7                           PinD6

// Buttons are directly    attached
#define BTN_EN1                               PinD3
#define BTN_EN2                               PinD2
#define BTN_ENC                               PinD4

// RS485 pins
//#define TX_ENABLE_PIN                       PinD4
//#define RX_ENABLE_PIN                       PinD5

//
// M3/M4/M5 - Spindle/Laser Control
//
#define SPINDLE_LASER_ENA_PIN                 PinB5  // Pullup or pulldown!
#define SPINDLE_LASER_PWM_PIN                 PinC0  // Hardware PWM
#define SPINDLE_DIR_PIN                       PinB6
