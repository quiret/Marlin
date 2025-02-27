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
 * ZONESTAR ZRIB V5.2 Based on MKS BASE v1.4 with A4982 stepper drivers and digital micro-stepping
 * Schematic: https://green-candy.osdn.jp/external/MarlinFW/board_schematics/RAMPS/ZONESTAR%20ZRIB%20V5.2/ZRIB_V52_Schematic.pdf
 * Origin: https://github.com/ZONESTAR3D/Control-Board/blob/main/8bit/ZRIB/ZRIB_V5/ZRIB_V52_Schematic.pdf
 * ATmega2560, ATmega1280
 */

#if HOTENDS > 2 || E_STEPPERS > 2
  #error "ZRIB V5.2 supports up to 2 hotends / E steppers."
#endif

#define BOARD_INFO_NAME "ZRIB V5.2"

#define MKS_BASE_VERSION                      14

//
// Heaters / Fans
//
#define HEATER_1_PIN                          PinH4
#define FAN_PIN                               PinH6  // PH6 ** Pin18 ** PWM9
#define FAN1_PIN                              PinH3

//
// Extra Extruder / Stepper for V5.2
//
#define E2_STEP_PIN                           PinG5
#define E2_DIR_PIN                            PinE3
#define E2_ENABLE_PIN                         PinA0

//
// Servos / XS3 Connector
//
#ifndef SERVO0_PIN
  #define SERVO0_PIN                          PinK3  // PWM
#endif
#ifndef SERVO1_PIN
  #define SERVO1_PIN                          PinK4  // PWM
#endif

#include "pins_MKS_BASE_common.h" // ... RAMPS

/**
 * Available connectors on MKS BASE v1.4 (Basically same as ZRIB V5.2)
 *
 *  =======
 *  | GND |
 *  |-----|   E0
 *  |  10 |                (10)  PB4 ** Pin23 ** PWM10
 *  |-----|
 *  | GND |
 *  |-----|   E1
 *  |  7  |                ( 7)  PH4 ** Pin16 ** PWM7
 *  |-----|
 *  | GND |
 *  |-----|   FAN
 *  |  9  |                ( 9)  PH6 ** Pin18 ** PWM9
 *  =======
 *
 *  =======
 *  | GND |
 *  |-----|   Heated Bed
 *  |  8  |                ( 8)  PH5 ** Pin17 ** PWM8
 *  =======
 *
 *  ==========
 *  | 12-24V |
 *  |--------|   Power
 *  |  GND   |
 *  ==========
 *
 * Servos / XS3 Connector
 *  =================
 *  | 65 | GND | 5V |      (65)  PK3 ** Pin86 ** A11
 *  |----|-----|----|
 *  | 66 | GND | 5V |      (66)  PK4 ** Pin85 ** A12
 *  =================
 *
 * ICSP
 *  =================
 *  | 5V | 51 | GND |      (51)  PB2 ** Pin21 ** SPI_MOSI
 *  |----|----|-----|
 *  | 50 | 52 | RST |      (50)  PB3 ** Pin22 ** SPI_MISO
 *  =================      (52)  PB1 ** Pin20 ** SPI_SCK
 *
 * XS6/AUX-1 Connector
 *  ======================
 *  | 5V | GND | NC | 20 | (20)  PD1 ** Pin44 ** I2C_SDA
 *  |----|-----|----|----|
 *  | 50 |  51 | 52 | 21 | (50)  PB3 ** Pin22 ** SPI_MISO
 *  ====================== (51)  PB2 ** Pin21 ** SPI_MOSI
 *                         (52)  PB1 ** Pin20 ** SPI_SCK
 *                         (21)  PD0 ** Pin43 ** I2C_SCL
 *
 * Temperature
 *  ==================================
 *  | GND | 69 | GND | 68 | GND | 67 |
 *  ==================================
 *                         (69)  PK7 ** Pin82 ** A15
 *                         (68)  PK6 ** Pin83 ** A14
 *                         (67)  PK5 ** Pin84 ** A13
 *
 * Limit Switches
 *  ============
 *  |  2 | GND | X+        ( 2)  PE4 ** Pin6  ** PWM2
 *  |----|-----|
 *  |  3 | GND | X-        ( 3)  PE5 ** Pin7  ** PWM3
 *  |----|-----|
 *  | 15 | GND | Y+        (15)  PJ0 ** Pin63 ** USART3_RX
 *  |----|-----|
 *  | 14 | GND | Y-        (14)  PJ1 ** Pin64 ** USART3_TX
 *  |----|-----|
 *  | 19 | GND | Z+        (19)  PD2 ** Pin45 ** USART1_RX
 *  |----|-----|
 *  | 18 | GND | Z-        (18)  PD3 ** Pin46 ** USART1_TX
 *  ============
 *
 * EXP1
 *  ============
 *  |  37 | 35 |           (37)  PC0 ** Pin53 ** D37
 *  |-----|----|           (35)  PC2 ** Pin55 ** D35
 *  |  17 | 16 |           (17)  PH0 ** Pin12 ** USART2_RX
 *  |-----|----|           (16)  PH1 ** Pin13 ** USART2_TX
 *  |  23 | 25 |           (23)  PA1 ** Pin77 ** D23
 *  |-----|----|           (25)  PA3 ** Pin75 ** D25
 *  |  27 | 29 |           (27)  PA5 ** Pin73 ** D27
 *  |-----|----|           (29)  PA7 ** Pin71 ** D29
 *  | GND | 5V |
 *  ============
 *
 * EXP2
 *  ============
 *  |  50 | 52 |           (50)  PB3 ** Pin22 ** SPI_MISO
 *  |-----|----|           (52)  PB1 ** Pin20 ** SPI_SCK
 *  |  31 | 53 |           (31)  PC6 ** Pin59 ** D31
 *  |-----|----|           (53)  PB0 ** Pin19 ** SPI_SS
 *  |  33 | 51 |           (33)  PC4 ** Pin57 ** D33
 *  |-----|----|           (51)  PB2 ** Pin21 ** SPI_MOSI
 *  |  49 | 41 |           (49)  PL0 ** Pin35 ** D49
 *  |-----|----|           (41)  PG0 ** Pin51 ** D41
 *  | GND | NC |
 *  ============
 */
