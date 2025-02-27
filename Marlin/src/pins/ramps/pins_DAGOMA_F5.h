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

// ATmega2560

#if HOTENDS > 2 || E_STEPPERS > 2
  #error "Dagoma3D F5 supports up to 2 hotends / E steppers."
#endif

#define BOARD_INFO_NAME "Dagoma3D F5"

//
// Endstops
//
#define X_STOP_PIN                         PinE4
#define Y_STOP_PIN                         PinE5
#define Z_STOP_PIN                         PinJ0

#define FIL_RUNOUT_PIN                     PinG2
#if EXTRUDERS > 1
  #define FIL_RUNOUT2_PIN                  PinJ1
#endif

// Alter timing for graphical display
#if IS_U8GLIB_ST7920
  #define BOARD_ST7920_DELAY_1                 0
  #define BOARD_ST7920_DELAY_2               250
  #define BOARD_ST7920_DELAY_3               250
#endif

//
// DAC steppers
//
#define HAS_MOTOR_CURRENT_DAC 1

#define DAC_STEPPER_ORDER { 0, 1, 2, 3 }

#define DAC_STEPPER_SENSE    0.11
#define DAC_STEPPER_ADDRESS  0
#define DAC_STEPPER_MAX      4096
#define DAC_STEPPER_VREF     1
#define DAC_STEPPER_GAIN     0
#define DAC_OR_ADDRESS       0x00

//
// Import default RAMPS 1.4 pins
//
#include "pins_RAMPS.h"
