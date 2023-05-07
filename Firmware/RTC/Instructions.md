# RTC Library Library Integration Guide

## Step 1:

 Download the `rtc.c` and `rtc.h` files from the provided source or from your own implementation.
## Step 2:

 Add the `rtc.c` file to your project's source folder and the `rtc.h` file to your project's include folder.
## Step 3: 

In your main program, add the following include statement to include the RTC library header file:

    ```c
    
    #include "rtc.h"
    ```

## Step 4: 

Initialize the RTC module using STM32CubeIDE GUI. Configure RTC clock source and enable RTC in the main initialization code or in the Clock Configuration function (SystemClock_Config).
## Step 5: 

In your code, call the `RTC_SetTime()` function to set the RTC time. The function takes the `RTC_HandleTypeDef` structure and three parameters for hours, minutes, and seconds. The function returns a `HAL_StatusTypeDef` value indicating the success or failure of the operation.

    ```c
    
    uint8_t hours = 12;
    uint8_t minutes = 30;
    uint8_t seconds = 0;
    HAL_StatusTypeDef status = RTC_SetTime(&hrtc, hours, minutes, seconds);
    if (status != HAL_OK) {
        // Handle error
    }

    ```

## Step 6: 

In your code, call the `RTC_GetTime()` function to get the RTC time. The function takes the `RTC_HandleTypeDef` structure and three pointers to `uint8_t` variables for hours, minutes, and seconds. The function returns a `HAL_StatusTypeDef` value indicating the success or failure of the operation.

    ```c
    
    uint8_t hours, minutes, seconds;
    HAL_StatusTypeDef status = RTC_GetTime(&hrtc, &hours, &minutes, &seconds);
    if (status != HAL_OK) {
        // Handle error
    }

    ```

## Step 7: 

Use the values of the `hours`, `minutes`, and `seconds` variables as needed in your program.

Note: The RTC module needs an external battery to retain the time when the device is powered off. The battery must be connected to the Vbat pin of the STM32 microcontroller.
