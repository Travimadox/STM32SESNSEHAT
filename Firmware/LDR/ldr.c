/*
 * LDR Library Source
 * Author: Travimadox Webb
 * Position: Embedded Software Engineer
 * Company: Imperium LLC
 * Date: 6th of May 2023
 */

#include "ldr.h"

// Calibration constants
static float m;
static float c;

// Initialize the LDR with calibration constants
void LDR_Init(void) {
    m = 2.675f;
    c = -66.88f;
}

// Read ADC value from the LDR
// hadc: pointer to an ADC_HandleTypeDef structure that contains
// the configuration information for the specified ADC
// returns: 32-bit unsigned integer ADC value
uint32_t LDR_ReadADC(ADC_HandleTypeDef *hadc) {
    uint32_t adc_value;

    // Start ADC conversion
    HAL_ADC_Start(hadc);

    // Poll for conversion completion
    if (HAL_ADC_PollForConversion(hadc, 10) == HAL_OK) {
        // Read ADC value
        adc_value = HAL_ADC_GetValue(hadc);
    }

    // Stop ADC conversion
    HAL_ADC_Stop(hadc);

    return adc_value;
}

// Read analog light intensity using the LDR
// hadc: pointer to an ADC_HandleTypeDef structure that contains
// the configuration information for the specified ADC
// returns: floating-point light intensity value
float LDR_ReadAnalogLightIntensity(ADC_HandleTypeDef *hadc) {
    uint32_t adc_value = LDR_ReadADC(hadc);
    return m * adc_value + c;
}
