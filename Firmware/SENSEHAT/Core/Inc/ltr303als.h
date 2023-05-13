/**
 * @file ltr303als.h
 * @brief LTR-303ALS Ambient Light Sensor Library Header
 * @author Travimadox Webb
 * @position Embedded Software Engineer
 * @company Imperium LLC
 * @date 7th of May 2023
 */

#ifndef LTR303ALS_H
#define LTR303ALS_H

#include "stm32f0xx_hal.h"

// LTR-303ALS I2C address (default: 0x29)
#define LTR303ALS_I2C_ADDRESS 0x29

/**
 * @brief Initialize the LTR-303ALS sensor.
 * @param hi2c Pointer to the I2C handle.
 * @param integration_time Integration time (in ms) for the sensor.
 * @param measurement_rate Measurement rate (in ms) for the sensor.
 * @return HAL status.
 */
HAL_StatusTypeDef LTR303ALS_Init(I2C_HandleTypeDef *hi2c, uint8_t integration_time, uint8_t measurement_rate);

/**
 * @brief Read light intensity data from the LTR-303ALS sensor.
 * @param hi2c Pointer to the I2C handle.
 * @param ch0 Pointer to store the channel 0 data.
 * @param ch1 Pointer to store the channel 1 data.
 * @return HAL status.
 */
HAL_StatusTypeDef LTR303ALS_ReadLightIntensity(I2C_HandleTypeDef *hi2c, uint16_t *ch0, uint16_t *ch1);

#endif // LTR303ALS_H
