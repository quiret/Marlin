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
 * BigTreeTech SKR 1.4 Turbo pin assignments
 * Schematic: https://green-candy.osdn.jp/external/MarlinFW/board_schematics/BTT%20SKR%20V1.4%20+%20Turbo/BTT%20SKR%20V1.4-SCH.pdf
 * Origin: https://github.com/bigtreetech/BIGTREETECH-SKR-V1.3/blob/master/BTT%20SKR%20V1.4/Hardware/BTT%20SKR%20V1.4-SCH.pdf
 */

#define BOARD_INFO_NAME "BTT SKR V1.4 TURBO"

#define LPC_MAINOSCILLATOR_FREQ 12000000

//
// Include SKR 1.4 pins
//
#define REQUIRE_LPC1769
#include "../lpc1768/pins_BTT_SKR_V1_4.h" // ... BTT_SKR_common
