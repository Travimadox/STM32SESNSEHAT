/**
 * @file ltr303als.c
 * @brief LTR-303ALS Ambient Light Sensor Library Implementation
 * @author Travimadox Webb
 * @position Embedded Software Engineer
 * @company Imperium LLC
 * @date 6th of May 2023
 */

#include "ltr303als.h"

static I2C_HandleTypeDef *i2c_handle;

/**
 * @brief Initialize the LTR-303ALS Ambient Light Sensor
 * @param hi2c Pointer to an I2C_HandleTypeDef structure that contains the configuration information for the specified I2C
 * @param integration_time Integration time for the LTR-303ALS
 * @param measurement_rate Measurement rate for the LTR-303ALS
 * @return HAL status (HAL_OK if successful, HAL_ERROR otherwise)
 */
HAL_StatusTypeDef LTR303ALS_Init(I2C_HandleTypeDef *hi2c, uint8_t integration_time, uint8_t measurement_rate) {
    i2c_handle = hi2c;

    // Enable ALS
    uint8_t command = 0x01; // For Gain x1
    if (HAL_I2C_Mem_Write(i2c_handle, LTR303ALS_I2C_ADDRESS << 1, 0x80, 1, &command, 1, HAL_MAX_DELAY) != HAL_OK) {
        return HAL_ERROR;
    }

    // Set ALS integration time and measurement rate
    uint8_t config = (integration_time << 3) | (measurement_rate & 0x07);
    if (HAL_I2C_Mem_Write(i2c_handle, LTR303ALS_I2C_ADDRESS << 1, 0x85, 1, &config, 1, HAL_MAX_DELAY) != HAL_OK) {
        return HAL_ERROR;
    }

    return HAL_OK;
}

/**
 * @brief Read light intensity from the LTR-303ALS Ambient Light Sensor
 * @param hi2c Pointer to an I2C_HandleTypeDef structure that contains the configuration information for the specified I2C
 * @param ch0 Pointer to a uint16_t variable to store the Channel 0 data
 * @param ch1 Pointer to a uint16_t variable to store the Channel 1 data
 * @return HAL status (HAL_OK if successful, HAL_ERROR otherwise)
 */
HAL_StatusTypeDef LTR303ALS_ReadLightIntensity(I2C_HandleTypeDef *hi2c, uint16_t *ch0, uint16_t *ch1) {
    uint8_t data[4];

    // Read channel 1 data
    if (HAL_I2C_Mem_Read(i2c_handle, LTR303ALS_I2C_ADDRESS << 1, 0x88, 1, data, 2, HAL_MAX_DELAY) != HAL_OK) {
        return HAL_ERROR;
    }
    *ch1 = (data[1] << 8) | data[0];

    // Read channel 0 data
    if (HAL_I2C_Mem_Read(i2c_handle, LTR303ALS_I2C_ADDRESS << 1, 0x8A, 1, data + 2, 2, HAL_MAX_DELAY) != HAL_OK) {
        return HAL_ERROR;
    }
    *ch0 = (data[3] << 8) | data[2];

    return HAL_OK;
}
