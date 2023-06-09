/**
 * @file rtc.c
 * @brief RTC Library Source
 * @author Travimadox Webb
 * @position Embedded Software Engineer
 * @company Imperium LLC
 * @date 7th May 2023
 *
 * @note IMPORTANT: Initialize the RTC module using STM32CubeIDE GUI.
 * Configure RTC clock source and enable RTC in the main initialization
 * code or in the Clock Configuration function (SystemClock_Config).
 */

#include "rtc.h"

/**
 * @brief Set the RTC time
 * @param hrtc Pointer to an RTC_HandleTypeDef structure that contains the configuration information for the specified RTC
 * @param hours Hours value to set (0-23)
 * @param minutes Minutes value to set (0-59)
 * @param seconds Seconds value to set (0-59)
 * @return HAL status (HAL_OK, HAL_ERROR, HAL_BUSY, or HAL_TIMEOUT)
 */
HAL_StatusTypeDef RTC_SetTime(RTC_HandleTypeDef *hrtc, uint8_t hours, uint8_t minutes, uint8_t seconds) {
    RTC_TimeTypeDef sTime = {0};

    sTime.Hours = hours;
    sTime.Minutes = minutes;
    sTime.Seconds = seconds;
    sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
    sTime.StoreOperation = RTC_STOREOPERATION_RESET;

    return HAL_RTC_SetTime(hrtc, &sTime, RTC_FORMAT_BIN);
}

/**
 * @brief Get the RTC time
 * @param hrtc Pointer to an RTC_HandleTypeDef structure that contains the configuration information for the specified RTC
 * @param hours Pointer to an uint8_t variable to store the hours value
 * @param minutes Pointer to an uint8_t variable to store the minutes value
 * @param seconds Pointer to an uint8_t variable to store the seconds value
 * @return HAL status (HAL_OK, HAL_ERROR, HAL_BUSY, or HAL_TIMEOUT)
 */
HAL_StatusTypeDef RTC_GetTime(RTC_HandleTypeDef *hrtc, uint8_t *hours, uint8_t *minutes, uint8_t *seconds) {
    RTC_TimeTypeDef sTime = {0};

    HAL_StatusTypeDef status = HAL_RTC_GetTime(hrtc, &sTime, RTC_FORMAT_BIN);
    if (status == HAL_OK) {
        *hours = sTime.Hours;
        *minutes = sTime.Minutes;
        *seconds = sTime.Seconds;
    }

    return status;
}

/**

@brief Set the RTC date
@param hrtc Pointer to an RTC_HandleTypeDef structure that contains the configuration information for the specified RTC
@param day The day of the month
@param month The month
@param year The year (from 0 to 99)
*/
void RTC_SetDate(RTC_HandleTypeDef *hrtc, uint8_t day, uint8_t month, uint8_t year) {
RTC_DateTypeDef date = {0};
date.Date = day;
date.Month = month;
date.Year = year;
HAL_RTC_SetDate(hrtc, &date, RTC_FORMAT_BIN);
}
/**

@brief Get the RTC date
@param hrtc Pointer to an RTC_HandleTypeDef structure that contains the configuration information for the specified RTC
@param day Pointer to store the day of the month
@param month Pointer to store the month
@param year Pointer to store the year
*/
void RTC_GetDate(RTC_HandleTypeDef *hrtc, uint8_t *day, uint8_t *month, uint8_t *year) {
RTC_DateTypeDef date = {0};
HAL_RTC_GetDate(hrtc, &date, RTC_FORMAT_BIN);
*day = date.Date;
*month = date.Month;
*year = date.Year;
}

