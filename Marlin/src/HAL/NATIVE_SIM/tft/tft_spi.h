/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2021 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
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

#include "../../../inc/MarlinConfig.h"

#ifndef LCD_READ_ID
  #define LCD_READ_ID  0x04   // Read display identification information (0xD3 on ILI9341)
#endif
#ifndef LCD_READ_ID4
  #define LCD_READ_ID4 0xD3   // Read display identification information (0xD3 on ILI9341)
#endif

#define DATASIZE_8BIT    8
#define DATASIZE_16BIT   16
#define TFT_IO_DRIVER TFT_SPI

#define TFT_SUPPORTS_8BIT

#define DMA_MINC_ENABLE 1
#define DMA_MINC_DISABLE 0

class TFT_SPI {
private:
  static uint32_t ReadID(uint16_t Reg);
  static void Transmit(uint16_t Data);
  static void TransmitDMA(uint32_t MemoryIncrease, uint16_t *Data, uint16_t Count);

public:
  // static SPIClass SPIx;

  static void Init();
  static uint32_t GetID();
  static bool isBusy();
  static void Abort();

  static void DataTransferBegin();
  static void DataTransferEnd();

  static void WriteData(uint16_t Data);
  static void WriteData8(uint8_t Data);
  static void WriteReg(uint16_t Reg);
  static void WriteReg8(uint8_t Reg);

  static void WriteSequence(uint16_t *Data, uint16_t Count);
  static void WriteMultiple(uint16_t Color, uint32_t Count);
};
