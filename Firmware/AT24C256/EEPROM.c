/**
  ******************************************************************************
  * @file    EEPROM.c
  * @brief   Using the HAL I2C Functions
  * @author  ControllersTech
  * @date    Feb 16, 2021
  ******************************************************************************
  * @attention
  *
  * Copyright (C) 2017 ControllersTech.com
  *
  * This is a free software under the GNU license, you can redistribute it and/or modify it under the terms
  * of the GNU General Public License version 3 as published by the Free Software Foundation.
  * This software library is shared with public for educational purposes, without WARRANTY and Author is not liable for any damages caused directly
  * or indirectly by this software, read more about this on the GNU General Public License.
  ******************************************************************************
  */

#include "EEPROM.h"
#include "math.h"
#include "string.h"

// Define the I2C
extern I2C_HandleTypeDef hi2c1;
#define EEPROM_I2C &hi2c1

// EEPROM ADDRESS (8bits)
#define EEPROM_ADDR 0xA0

// Define the Page Size and number of pages
#define PAGE_SIZE 64     // in Bytes
#define PAGE_NUM  512    // number of pages

/**
  * @brief  Calculate the remaining bytes to write.
  * @param  size: Size of the data.
  * @param  offset: Start byte offset in the page.
  * @retval Number of bytes remaining to write.
  */
static uint16_t bytestowrite(uint16_t size, uint16_t offset)
{
  if ((size + offset) < PAGE_SIZE) return size;
  else return PAGE_SIZE - offset;
}

/**
  * @brief  Convert float to bytes.
  * @param  ftoa_bytes_temp: Pointer to the byte array.
  * @param  float_variable: Float value to convert.
  * @retval None.
  */
static void float2Bytes(uint8_t *ftoa_bytes_temp, float float_variable)
{
  union {
    float a;
    uint8_t bytes[4];
  } thing;

  thing.a = float_variable;

  for (uint8_t i = 0; i < 4; i++) {
    ftoa_bytes_temp[i] = thing.bytes[i];
  }
}

/**
  * @brief  Convert bytes to float.
  * @param  ftoa_bytes_temp: Pointer to the byte array.
  * @retval Converted float value.
  */
static float Bytes2float(uint8_t *ftoa_bytes_temp)
{
  union {
    float a;
    uint8_t bytes[4];
  } thing;

  for (uint8_t i = 0; i < 4; i++) {
    thing.bytes[i] = ftoa_bytes_temp[i];
  }

  float float_variable = thing.a;
  return float_variable;
}

void EEPROM_Write(uint16_t page, uint16_t offset, uint8_t *data, uint16_t size)
{
  // Find out the number of bit, where the page addressing starts
  int paddrposition = log(PAGE_SIZE) / log(2);

  // Calculate the start page and the end page
  uint16_t startPage = page;
  uint16_t endPage = page + ((size + offset) / PAGE_SIZE);

  // Number of pages to be written
  uint16_t numofpages = (endPage - startPage) + 1;
  uint16_t pos = 0;

  // Write the data
  for (int i = 0; i < numofpages; i++)
  {
        // Calculate the address of the memory location
    // Here we add the page address with the byte address
    uint16_t MemAddress = startPage << paddrposition | offset;
    uint16_t bytesremaining = bytestowrite(size, offset);  // Calculate the remaining bytes to be written

    HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, MemAddress, 2, &data[pos], bytesremaining, 1000);  // Write the data to the EEPROM

    startPage += 1;  // Increment the page, so that a new page address can be selected for further write
    offset = 0;   // Since we will be writing to a new page, so offset will be 0
    size = size - bytesremaining;  // Reduce the size of the bytes
    pos += bytesremaining;  // Update the position for the data buffer

    HAL_Delay(5);  // Write cycle delay (5ms)
  }
}

/**
  * @brief  Write a float/integer value to the EEPROM.
  * @param  page: Number of the start page. Range from 0 to PAGE_NUM-1.
  * @param  offset: Start byte offset in the page. Range from 0 to PAGE_SIZE-1.
  * @param  data: Float/integer value that you want to write.
  * @retval None.
  */
void EEPROM_Write_NUM(uint16_t page, uint16_t offset, float data)
{
  float2Bytes(bytes_temp, data);

  EEPROM_Write(page, offset, bytes_temp, 4);
}

/**
  * @brief  Read a single float/integer value from the EEPROM.
  * @param  page: Number of the start page. Range from 0 to PAGE_NUM-1.
  * @param  offset: Start byte offset in the page. Range from 0 to PAGE_SIZE-1.
  * @retval Float/integer value.
  */
float EEPROM_Read_NUM(uint16_t page, uint16_t offset)
{
  uint8_t buffer[4];

  EEPROM_Read(page, offset, buffer, 4);

  return (Bytes2float(buffer));
}

/**
  * @brief  Read data from the EEPROM.
  * @param  page: Number of the start page. Range from 0 to PAGE_NUM-1.
  * @param  offset: Start byte offset in the page. Range from 0 to PAGE_SIZE-1.
  * @param  data: Pointer to the data to write in bytes.
  * @param  size: Size of the data.
  * @retval None.
  */
void EEPROM_Read(uint16_t page, uint16_t offset, uint8_t *data, uint16_t size)
{
  int paddrposition = log(PAGE_SIZE) / log(2);

  uint16_t startPage = page;
  uint16_t endPage = page + ((size + offset) / PAGE_SIZE);

  uint16_t numofpages = (endPage - startPage) + 1;
  uint16_t pos = 0;

  for (int i = 0; i < numofpages; i++)
  {
    uint16_t MemAddress = startPage << paddrposition | offset;
    uint16_t bytesremaining = bytestowrite(size, offset);
    HAL_I2C_Mem_Read(EEPROM_I2C, EEPROM_ADDR, MemAddress, 2, &data[pos], bytesremaining, 1000);
    startPage += 1;
    offset = 0;
    size = size - bytesremaining;
    pos += bytesremaining;
  }
}

/**
  * @brief  Erase a page in the EEPROM Memory
  * @param  page: Number of page to erase
  *         In order to erase multiple pages, just use this function in the for loop
  * @retval None
  */
void EEPROM_PageErase(uint16_t page)
{
  // Calculate the memory address based on the page number
  int paddrposition = log(PAGE_SIZE) / log(2);
  uint16_t MemAddress = page << paddrposition;

  // Create a buffer to store the reset values
  uint8_t data[PAGE_SIZE];
  memset(data, 0xff, PAGE_SIZE);

  // Write the data to the EEPROM
  HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, MemAddress, 2, data, PAGE_SIZE, 1000);

  HAL_Delay(5);  // Write cycle delay (5ms)
}
