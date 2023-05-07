# LTR-303ALS Ambient Light Sensor Integration Guide

This guide will help you integrate the `ltr303als.h` and `ltr303als.c` files into your STM32 project using the LTR-303ALS Ambient Light Sensor.

## Step 1: Download the library files

Download the following files:

- `ltr303als.h`
- `ltr303als.c`

## Step 2: Add the library files to your project

1. Open your STM32 project in the STM32CubeIDE or your preferred IDE.
2. Copy the `ltr303als.h` file into the `Inc` folder of your project.
3. Copy the `ltr303als.c` file into the `Src` folder of your project.

## Step 3: Include the library in your code

In the source file where you want to use the LTR-303ALS library (usually `main.c`), add the following line at the beginning of the file:

```c

#include "ltr303als.h"
```

## Step 4: Initialize the sensor

Initialize the LTR-303ALS sensor by calling the `LTR303ALS_Init` function, passing a pointer to an `I2C_HandleTypeDef` structure and the desired integration time and measurement rate.

```c

I2C_HandleTypeDef hi2c1; // This should be configured and initialized using HAL

if (LTR303ALS_Init(&hi2c1, INTEGRATION_TIME, MEASUREMENT_RATE) != HAL_OK) {
    // Handle initialization error
}
```

## Step 5: Read light intensity

To read the light intensity from the sensor, call the `LTR303ALS_ReadLightIntensity` function, passing a pointer to an `I2C_HandleTypeDef` structure and pointers to two `uint16_t` variables that will store the values of channels 0 and 1.

```c

uint16_t ch0, ch1;

if (LTR303ALS_ReadLightIntensity(&hi2c1, &ch0, &ch1) != HAL_OK) {
    // Handle read error
} else {
    // Process light intensity data
}
```
