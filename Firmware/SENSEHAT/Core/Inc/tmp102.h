/*
 * TMP102 Temperature Sensor Library
 * Author: Travimadox Webb
 * Postion: Embedded Software Engineer
 * Company: Imperium LLC
 * Date: 6th of May 2023
 */

#ifndef TMP102_H
#define TMP102_H

#include "stm32f0xx_hal.h"

// TMP102 I2C address (default: 0x48)
#define TMP102_I2C_ADDRESS 0x48

// TMP102 register addresses
#define TMP102_REG_TEMPERATURE 0x00
#define TMP102_REG_CONFIG 0x01

// TMP102 configuration settings
#define TMP102_CONFIG_CONTINUOUS_CONVERSION 0x0000
#define TMP102_CONFIG_SHUTDOWN_MODE 0x0100

// Initialize the TMP102 sensor
HAL_StatusTypeDef TMP102_Init(I2C_HandleTypeDef *hi2c);

// Read temperature from the TMP102 sensor
float TMP102_ReadTemperature(I2C_HandleTypeDef *hi2c);

#endif // TMP102_H
