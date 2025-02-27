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
 * Melzi (Malyan M150) pin assignments
 * ATmega644P, ATmega1284P
 */

#define BOARD_INFO_NAME "Melzi (Malyan)"

#if ENABLED(CR10_STOCKDISPLAY)
  #define LCD_PINS_RS                         PinC1  // ST9720 CS
  #define LCD_PINS_ENABLE                     PinC0  // ST9720 DAT
  #define LCD_PINS_D4                         PinD3  // ST9720 CLK
  #define BTN_EN1                             PinA1
  #define BTN_EN2                             PinA2
  #define BTN_ENC                             PinA3

  #define LCD_PINS_DEFINED
#endif

#include "pins_MELZI.h" // ... SANGUINOLOLU_12 ... SANGUINOLOLU_11
