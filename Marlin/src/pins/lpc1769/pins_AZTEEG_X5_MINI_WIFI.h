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
 * Azteeg X5 MINI WIFI pin assignments
 * Wiring diagram: https://green-candy.osdn.jp/external/MarlinFW/board_schematics/Azteeg%20X5%20MINI%20WIFI/x5mini_wifi_wiring.pdf
 * Origin: http://files.panucatt.com/datasheets/x5mini_wifi_wiring.pdf
 */

#include "env_validate.h"

#define BOARD_INFO_NAME "Azteeg X5 MINI WIFI"

// Just a wild guess because no schematics!
#define LPC_MAINOSCILLATOR_FREQ 12000000

//
// DIGIPOT slave addresses
//
#ifndef DIGIPOT_I2C_ADDRESS_A
  #define DIGIPOT_I2C_ADDRESS_A 0x58   // shifted slave address for first DIGIPOT (0x58 <- 0x2C << 1)
#endif
#ifndef DIGIPOT_I2C_ADDRESS_B
  #define DIGIPOT_I2C_ADDRESS_B 0x5C   // shifted slave address for second DIGIPOT (0x5C <- 0x2E << 1)
#endif

#include "pins_AZTEEG_X5_MINI.h"
