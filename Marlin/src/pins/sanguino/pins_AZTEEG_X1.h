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
 * Azteeg X1 pin assignments
 * Schematic: https://green-candy.osdn.jp/external/MarlinFW/board_schematics/Azteeg%20X1/Azteeg_X1_schematics.pdf
 * Origin: https://reprap.org/mediawiki/images/0/07/Azteeg_X1_schematics.pdf
 */

#define BOARD_INFO_NAME "Azteeg X1"

#define AVR_CHIPOSCILLATOR_FREQ 16000000

#define FAN_PIN 4

#include "pins_SANGUINOLOLU_12.h" // ... SANGUINOLOLU_11
