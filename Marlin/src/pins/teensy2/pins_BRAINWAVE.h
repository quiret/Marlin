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
 * Brainwave 1.0 pin assignments (AT90USB646)
 * https://www.reprap.org/wiki/Brainwave
 *
 * Requires hardware bundle for Arduino:
 * https://github.com/unrepentantgeek/brainwave-arduino
 *
 * Schematic: https://green-candy.osdn.jp/external/MarlinFW/board_schematics/Brainwave/schematic.pdf
 * Origin: https://github.com/unrepentantgeek/Brainwave/blob/master/brainwave/brainwave.sch
 */

/**
 *  Rev B  16 JAN 2017
 *
 *  Added pointer to a currently available Arduino IDE extension that will
 *  allow this board to use the latest Marlin software
 */

/**
 *  Rev C  2 JUN 2017
 *
 *  Converted to Arduino pin numbering
 */

/**
 *  Marlin_AT90USB - https://github.com/Bob-the-Kuhn/Marlin_AT90USB
 *    This is the only known IDE extension that is compatible with the pin definitions
 *    in this file, Adrduino 1.6.12 and the latest mainstream Marlin software.
 *
 *    "Marlin_AT90USB" makes PWM0A available rather than the usual PWM1C. These PWMs share
 *    the same physical pin. Marlin uses TIMER1 to generate interrupts and sets it up such
 *    that PWM1A, PWM1B & PWM1C can't be used.
 *
 *  Installation:
 *
 *    1. In the Arduino IDE, under Files -> Preferences paste the following URL
 *       https://rawgit.com/Bob-the-Kuhn/Marlin_AT90USB/master/package_MARLIN_AT90USB_index.json
 *    2. Under Tools > Board -> Boards manager, scroll to the bottom, click on MARLIN_AT90USB
 *       and then click on "Install"
 *    3. Select "AT90USB646_TEENSYPP" from the 'Tools > Board' menu.
 */

/**
 *  To burn the bootloader that comes with Marlin_AT90USB:
 *
 *    1. Connect your programmer to the board.
 *    2. In Arduino IDE select "AT90USB646_TEENSYPP" and then select the programmer.
 *    3. In Arduino IDE click on "burn bootloader". Don't worry about the "verify failed at 1F000" error message.
 *    4. The programmer is no longer needed. Remove it.
 */

#if NOT_TARGET(__AVR_AT90USB646__)
  #error "Oops! Select 'Brainwave' in 'Tools > Board.'"
#endif

#define BOARD_INFO_NAME "Brainwave"

#define AVR_CHIPOSCILLATOR_FREQ 16000000

//
// Limit Switches
//
#define X_STOP_PIN                            PinA7  // A7
#define Y_STOP_PIN                            PinA6  // A6
#define Z_STOP_PIN                            PinA5  // A5

//
// Steppers
//
#define X_STEP_PIN                            PinD3  // D3
#define X_DIR_PIN                             PinD5  // D5
#define X_ENABLE_PIN                          PinD4  // D4
#define X_ATT_PIN                             PinD2  // D2

#define Y_STEP_PIN                            PinD7  // D7
#define Y_DIR_PIN                             PinE1  // E1
#define Y_ENABLE_PIN                          PinE0  // E0
#define Y_ATT_PIN                             PinD6  // D6

#define Z_STEP_PIN                            PinC1  // C1
#define Z_DIR_PIN                             PinC3  // C3
#define Z_ENABLE_PIN                          PinC2  // C2
#define Z_ATT_PIN                             PinC0  // C0

#define E0_STEP_PIN                           PinC5  // C5
#define E0_DIR_PIN                            PinC7  // C7
#define E0_ENABLE_PIN                         PinC6  // C6
#define E0_ATT_PIN                            PinC4  // C4

//
// Temperature Sensors
//
#define TEMP_0_PIN                            PinD7  // F7  Analog Input
#define TEMP_BED_PIN                          PinD6  // F6  Analog Input

//
// Heaters / Fans
//
#define HEATER_0_PIN                          PinA4  // A4 Extruder
#define HEATER_BED_PIN                        PinE6  // E6 Bed

#ifndef FAN_PIN
  #define FAN_PIN                             PinA3  // A3 Fan
#endif

//
// Misc. Functions
//
#define LED_PIN                               PinE7  // E7
