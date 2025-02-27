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
 * Open Motion controller with enable based extruders (Final!)
 *
 *                        ATmega644
 *
 *                        +---\/---+
 *            (D 0) PB0  1|        |40  PA0 (AI 0 / D31)
 *            (D 1) PB1  2|        |39  PA1 (AI 1 / D30)
 *       INT2 (D 2) PB2  3|        |38  PA2 (AI 2 / D29)
 *        PWM (D 3) PB3  4|        |37  PA3 (AI 3 / D28)
 *        PWM (D 4) PB4  5|        |36  PA4 (AI 4 / D27)
 *       MOSI (D 5) PB5  6|        |35  PA5 (AI 5 / D26)
 *       MISO (D 6) PB6  7|        |34  PA6 (AI 6 / D25)
 *        SCK (D 7) PB7  8|        |33  PA7 (AI 7 / D24)
 *                  RST  9|        |32  AREF
 *                  VCC 10|        |31  GND
 *                  GND 11|        |30  AVCC
 *                XTAL2 12|        |29  PC7 (D 23)
 *                XTAL1 13|        |28  PC6 (D 22)
 *       RX0 (D 8)  PD0 14|        |27  PC5 (D 21) TDI
 *       TX0 (D 9)  PD1 15|        |26  PC4 (D 20) TDO
 *  INT0 RX1 (D 10) PD2 16|        |25  PC3 (D 19) TMS
 *  INT1 TX1 (D 11) PD3 17|        |24  PC2 (D 18) TCK
 *       PWM (D 12) PD4 18|        |23  PC1 (D 17) SDA
 *       PWM (D 13) PD5 19|        |22  PC0 (D 16) SCL
 *       PWM (D 14) PD6 20|        |21  PD7 (D 15) PWM
 *                        +--------+
 *
 * REF http://sanguino.wikidot.com/hardware
 */

/**
 * Rev B    26 DEC 2016
 *
 * added pointer to a current Arduino IDE extension
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
 * Installation instructions can be found at http://learn.sparkfun.com/pages/CustomBoardsArduino
 * Just use the above JSON URL instead of Sparkfun's JSON.
 *
 * Once installed select the Sanguino board and then select the CPU.
 */

#if NOT_TARGET(__AVR_ATmega644P__, __AVR_ATmega644__)
  #error "Oops! Select 'Sanguino' in 'Tools > Board' and 'ATmega644' or 'ATmega644P' in 'Tools > Processor.'"
#endif

#define BOARD_INFO_NAME "Final OMCA"

// Just a wild guess because no schematics!
#define AVR_CHIPOSCILLATOR_FREQ 16000000

//
// Limit Switches
//
#define X_STOP_PIN                         PinB0
#define Y_STOP_PIN                         PinB1
#define Z_STOP_PIN                         PinB2

//
// Steppers
//
#define X_STEP_PIN                         PinA5
#define X_DIR_PIN                          PinA6
#define X_ENABLE_PIN                       PinD2

#define Y_STEP_PIN                         PinA3
#define Y_DIR_PIN                          PinA4
#define Y_ENABLE_PIN                       PinD2

#define Z_STEP_PIN                         PinC7
#define Z_DIR_PIN                          PinC6
#define Z_ENABLE_PIN                       PinD2

#define E0_STEP_PIN                        PinA7
#define E0_DIR_PIN                         PinC5
#define E0_ENABLE_PIN                      PinD2

#define E1_STEP_PIN                           -1  // 21
#define E1_DIR_PIN                            -1  // 20
#define E1_ENABLE_PIN                         -1  // 19

#define E2_STEP_PIN                           -1  // 21
#define E2_DIR_PIN                            -1  // 20
#define E2_ENABLE_PIN                         -1  // 18

//
// Temperature Sensors
//
#define TEMP_0_PIN                         PinB0  // Analog Input
#define TEMP_1_PIN                         PinB1  // Analog Input
#define TEMP_BED_PIN                       PinB2  // Analog Input (1,2 or I2C)

//
// Heaters / Fans
//
#define HEATER_0_PIN                       PinB3  // DONE PWM on RIGHT connector
#define HEATER_BED_PIN                     PinB4

#ifndef FAN_PIN
  #define FAN_PIN                          PinD6  // PWM on MIDDLE connector
#endif

//
// Misc. Functions
//
#define SDSS                               PinD3

#define I2C_SCL_PIN                        PinC0
#define I2C_SDA_PIN                        PinC1

// future proofing
#define __FS                               PinC4
#define __FD                               PinC3
#define __GS                               PinC2
#define __GD                               PinD5

#define UNUSED_PWM                         PinD6  // PWM on LEFT connector
