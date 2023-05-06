
/*
 * LDR Library Header
 * Author: Travimadox Webb
 * Postion: Embedded Software Engineer
 * Company: Imperium LLC
 * Date: 6th of May 2023
 */

#ifndef LDR_H
#define LDR_H

#include "stm32f0xx_hal.h"


// Initialize the LDR
void LDR_Init(void);

// Read ADC value from the LDR
uint32_t LDR_ReadADC(ADC_HandleTypeDef *hadc);

// Read analog light intensity using the LDR
float LDR_ReadAnalogLightIntensity(ADC_HandleTypeDef *hadc);

#endif // LDR_H
