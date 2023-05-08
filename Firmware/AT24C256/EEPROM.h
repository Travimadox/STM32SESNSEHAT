/**
  ******************************************************************************
  * @file    EEPROM.h
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

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

#include "stdint.h"
#include "stm32f4xx_hal.h"

/**
  * @brief  Write data to the EEPROM.
  * @param  page: Start page number (0 to PAGE_NUM-1).
  * @param  offset: Start byte offset in the page (0 to PAGE_SIZE-1).
  * @param  data: Pointer to the data to write in bytes.
  * @param  size: Size of the data.
  * @retval None
  */
void EEPROM_Write(uint16_t page, uint16_t offset, uint8_t *data, uint16_t size);

/**
  * @brief  Read data from the EEPROM.
  * @param  page: Start page number (0 to PAGE_NUM-1).
  * @param  offset: Start byte offset in the page (0 to PAGE_SIZE-1).
  * @param  data: Pointer to the data to read in bytes.
  * @param  size: Size of the data.
  * @retval None
  */
void EEPROM_Read(uint16_t page, uint16_t offset, uint8_t *data, uint16_t size);

/**
  * @brief  Erase a page in the EEPROM Memory.
  * @param  page: Page number to erase.
  * @retval None
  */
void EEPROM_PageErase(uint16_t page);

/**
  * @brief  Write a float or integer value to the EEPROM.
  * @param  page: Start page number (0 to PAGE_NUM-1).
  * @param  offset: Start byte offset in the page (0 to PAGE_SIZE-1).
  * @param  fdata: Float or integer value to write.
  * @retval None
  */
void EEPROM_Write_NUM(uint16_t page, uint16_t offset, float fdata);

/**
  * @brief  Read a float or integer value from the EEPROM.
  * @param  page: Start page number (0 to PAGE_NUM-1).
  * @param  offset: Start byte offset in the page (0 to PAGE_SIZE-1).
  * @retval Float or integer value read from the EEPROM.
  */
float EEPROM_Read_NUM(uint16_t page, uint16_t offset);

#endif /* INC_EEPROM_H_ */
