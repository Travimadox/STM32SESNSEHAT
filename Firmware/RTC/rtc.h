/**
 * @file rtc.h
 * @brief RTC Library Header
 * @author Travimadox Webb
 * @position Embedded Software Engineer
 * @company Imperium LLC
 * @date 7th May 2023
 */

#ifndef __RTC_H
#define __RTC_H

#include "stm32f0xx_hal.h"

/**
 * @brief Set the RTC time
 * @param hrtc Pointer to an RTC_HandleTypeDef structure that contains the configuration information for the specified RTC
 * @param hours Hours value to set (0-23)
 * @param minutes Minutes value to set (0-59)
 * @param seconds Seconds value to set (0-59)
 * @return HAL status (HAL_OK, HAL_ERROR, HAL_BUSY, or HAL_TIMEOUT)
 */
HAL_StatusTypeDef RTC_SetTime(RTC_HandleTypeDef *hrtc, uint8_t hours, uint8_t minutes, uint8_t seconds);

/**
 * @brief Get the RTC time
 * @param hrtc Pointer to an RTC_HandleTypeDef structure that contains the configuration information for the specified RTC
 * @param hours Pointer to an uint8_t variable to store the hours value
 * @param minutes Pointer to an uint8_t variable to store the minutes value
 * @param seconds Pointer to an uint8_t variable to store the seconds value
 * @return HAL status (HAL_OK, HAL_ERROR, HAL_BUSY, or HAL_TIMEOUT)
 */
HAL_StatusTypeDef RTC_GetTime(RTC_HandleTypeDef *hrtc, uint8_t *hours, uint8_t *minutes, uint8_t *seconds);

#endif // __RTC_H
