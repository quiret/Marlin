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
 * Melzi (Creality) pin assignments
 * Schematic: https://green-candy.osdn.jp/external/MarlinFW/board_schematics/Melzi%20(Creality)/CR-10%20Schematic.pdf
 * Origin: https://github.com/Creality3DPrinting/CR10-Melzi-1.1.2/blob/master/Circuit%20diagram/Motherboard/CR-10%20Schematic.pdf
 * ATmega1284P
 *
 * The Creality board needs a bootloader installed before Marlin can be uploaded.
 * If you don't have a chip programmer you can use a spare Arduino plus a few
 * electronic components to write the bootloader.
 *
 * See https://www.instructables.com/id/Burn-Arduino-Bootloader-with-Arduino-MEGA/
 *
 * Schematic: https://bit.ly/2XOnsWb
 */

#define BOARD_INFO_NAME "Melzi (Creality)"

#define AVR_CHIPOSCILLATOR_FREQ 16000000

// Alter timing for graphical display
#if IS_U8GLIB_ST7920
  #define BOARD_ST7920_DELAY_1               125
  #define BOARD_ST7920_DELAY_2               125
  #define BOARD_ST7920_DELAY_3               125
#endif

//
// LCD / Controller
//
#if ANY(MKS_MINI_12864, CR10_STOCKDISPLAY, ENDER2_STOCKDISPLAY)
  #if ENABLED(CR10_STOCKDISPLAY)
    #define LCD_PINS_RS                       PinA3  // ST9720 CS
    #define LCD_PINS_ENABLE                   PinC1  // ST9720 DAT
    #define LCD_PINS_D4                       PinA1  // ST9720 CLK
  #elif EITHER(MKS_MINI_12864, ENDER2_STOCKDISPLAY)
    #define DOGLCD_CS                         PinA3
    #define DOGLCD_A0                         PinA1
  #endif

  #define LCD_SDSS                            31  // Controller's SD card

  #define BTN_ENC                             16
  #define BTN_EN1                             11
  #define BTN_EN2                             10
  #define BEEPER_PIN                          27

  #define LCD_PINS_DEFINED

#endif

#include "pins_MELZI.h" // ... SANGUINOLOLU_12 ... SANGUINOLOLU_11

#if ENABLED(BLTOUCH)
  #ifndef SERVO0_PIN
    #define SERVO0_PIN                        PinA4
  #endif
  #if SERVO0_PIN == BEEPER_PIN
    #undef BEEPER_PIN
  #endif
#elif HAS_FILAMENT_SENSOR
  #ifndef FIL_RUNOUT_PIN
    #define FIL_RUNOUT_PIN                    PinA4
  #endif
  #if FIL_RUNOUT_PIN == BEEPER_PIN
    #undef BEEPER_PIN
  #endif
#endif

#if ENABLED(MINIPANEL)
  #undef DOGLCD_CS
  #define DOGLCD_CS                  LCD_PINS_RS
#endif

/**
  PIN:   0   Port: B0        E0_DIR_PIN                  protected
  PIN:   1   Port: B1        E0_STEP_PIN                 protected
  PIN:   2   Port: B2        Z_DIR_PIN                   protected
  PIN:   3   Port: B3        Z_STEP_PIN                  protected
  PIN:   4   Port: B4        AVR_SS_PIN                  protected
  .                          FAN_PIN                     protected
  .                       SD_SS_PIN                      protected
  PIN:   5   Port: B5        AVR_MOSI_PIN                Output = 1
  .                       SD_MOSI_PIN                    Output = 1
  PIN:   6   Port: B6        AVR_MISO_PIN                Input  = 0    TIMER3A   PWM:     0    WGM: 1    COM3A: 0    CS: 3    TCCR3A: 1    TCCR3B: 3    TIMSK3: 0
  .                       SD_MISO_PIN                    Input  = 0
  PIN:   7   Port: B7        AVR_SCK_PIN                 Output = 0    TIMER3B   PWM:     0    WGM: 1    COM3B: 0    CS: 3    TCCR3A: 1    TCCR3B: 3    TIMSK3: 0
  .                       SD_SCK_PIN                     Output = 0
  PIN:   8   Port: D0        RXD                         Input  = 1
  PIN:   9   Port: D1        TXD                         Input  = 0
  PIN:  10   Port: D2        BTN_EN2                     Input  = 1
  PIN:  11   Port: D3        BTN_EN1                     Input  = 1
  PIN:  12   Port: D4        HEATER_BED_PIN              protected
  PIN:  13   Port: D5        HEATER_0_PIN                protected
  PIN:  14   Port: D6        E0_ENABLE_PIN               protected
  .                          X_ENABLE_PIN                protected
  .                          Y_ENABLE_PIN                protected
  PIN:  15   Port: D7        X_STEP_PIN                  protected
  PIN:  16   Port: C0        BTN_ENC                     Input  = 1
  .                          SCL                         Input  = 1
  PIN:  17   Port: C1        LCD_PINS_ENABLE             Output = 0
  .                          SDA                         Output = 0
  PIN:  18   Port: C2        X_MIN_PIN                   protected
  .                          X_STOP_PIN                  protected
  PIN:  19   Port: C3        Y_MIN_PIN                   protected
  .                          Y_STOP_PIN                  protected
  PIN:  20   Port: C4        Z_MIN_PIN                   protected
  .                          Z_STOP_PIN                  protected
  PIN:  21   Port: C5        X_DIR_PIN                   protected
  PIN:  22   Port: C6        Y_STEP_PIN                  protected
  PIN:  23   Port: C7        Y_DIR_PIN                   protected
  PIN:  24   Port: A7        TEMP_0_PIN                  protected
  PIN:  25   Port: A6        TEMP_BED_PIN                protected
  PIN:  26   Port: A5        Z_ENABLE_PIN                protected
  PIN:  27   Port: A4        BEEPER_PIN                  Output = 0
  PIN:  28   Port: A3        LCD_PINS_RS                 Output = 0
  PIN:  29   Port: A2        <unused/unknown>            Input  = 0
  PIN:  30   Port: A1        LCD_PINS_D4                 Output = 1
  PIN:  31   Port: A0        SDSS                        Output = 1
*/

/**
 *    EXP1 Connector                      EXP1 as CR10 STOCKDISPLAY
 *        ------                                      ------
 *   PA4 | 1  2 | PC0                     BEEPER_PIN | 1  2 | BTN_ENC
 *   PD3 | 3  4 | RESET                      BTN_EN1 | 3  4 | RESET
 *   PD2   5  6 | PA1                        BTN_EN2   5  6 | LCD_PINS_D4     (ST9720 CLK)
 *   PA3 | 7  8 | PC1        (ST9720 CS) LCD_PINS_RS | 7  8 | LCD_PINS_ENABLE (ST9720 DAT)
 *   GND | 9 10 | 5V                             GND | 9 10 | 5V
 *        ------                                      ------
 */
