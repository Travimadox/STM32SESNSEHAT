
/**
 * @file tmp102.c
 * @brief TMP102 Temperature Sensor Library
 * @author Travimadox Webb
 * @position Embedded Software Engineer
 * @company Imperium LLC
 * @date 6th of May 2023
 */

#include "tmp102.h"

// I2C handle for communication with the sensor
static I2C_HandleTypeDef *i2c_handle;

/**
 * @brief Initialize the TMP102 temperature sensor.
 * @param hi2c Pointer to an I2C_HandleTypeDef structure that contains
 *         the configuration information for the specified I2C peripheral.
 * @retval HAL status
 */
HAL_StatusTypeDef TMP102_Init(I2C_HandleTypeDef *hi2c) {
    i2c_handle = hi2c;

    uint16_t config = TMP102_CONFIG_CONTINUOUS_CONVERSION;
    uint8_t data[2] = {config >> 8, config & 0xFF};

    // Write config to the TMP102
    if (HAL_I2C_Mem_Write(i2c_handle, TMP102_I2C_ADDRESS << 1, TMP102_REG_CONFIG, 1, data, 2, HAL_MAX_DELAY) != HAL_OK) {
        return HAL_ERROR;
    }

    return HAL_OK;
}

/**
 * @brief Read temperature from the TMP102 sensor.
 * @param hi2c Pointer to an I2C_HandleTypeDef structure that contains
 *         the configuration information for the specified I2C peripheral.
 * @return Temperature in degrees Celsius as a float.
 */
float TMP102_ReadTemperature(I2C_HandleTypeDef *hi2c) {
    uint8_t data[2];

    // Read temperature data from the TMP102
    if (HAL_I2C_Mem_Read(i2c_handle, TMP102_I2C_ADDRESS << 1, TMP102_REG_TEMPERATURE, 1, data, 2, HAL_MAX_DELAY) != HAL_OK) {
        return NAN;
    }

    int16_t raw_temperature = (data[0] << 4) | (data[1] >> 4);

    // Convert raw temperature data to Celsius
    return (float) raw_temperature * 0.0625f;
}
