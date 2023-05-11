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

In your code, call the `RTC_SetDate()` function to set the RTC date.

```c
uint8_t day = 11;
uint8_t month = 5;
uint8_t year = 23; // It's usually the year minus 2000.

RTC_SetDate(&hrtc, day, month, year);
```
Now, the RTC date is set to 11th of May, 2023.


## Step 8:

In your code, call the `RTC_GetDate()` function to get the RTC date. You can retrieve the date using `RTC_GetDate` as follows:

```c
uint8_t day;
uint8_t month;
uint8_t year;

RTC_GetDate(&hrtc, &day, &month, &year);

printf("Current date: %02d-%02d-%02d\n", day, month, year + 2000); // Adding 2000 to get the full year.

```

## Step 9: 

Use the values of the `hours`, `minutes`, `seconds`,`day` ,`month`,`year`variables as needed in your program.

Note: The RTC module needs an external battery to retain the time when the device is powered off. The battery must be connected to the Vbat pin of the STM32 microcontroller. An external battery is not used in our setup so the time needs to be reset every time the STM32 goes off. However an external battery can be implemented to overcome this.

## Example:
Below is an example:
```c
    #include "rtc.h"

int main(void) {
    RTC_HandleTypeDef hrtc;
    uint8_t hours = 12;
    uint8_t minutes = 30;
    uint8_t seconds = 0;
    HAL_StatusTypeDef status = RTC_SetTime(&hrtc, hours, minutes, seconds);
    if (status != HAL_OK) {
        // Handle error
    }

    uint8_t read_hours, read_minutes, read_seconds;
    status = RTC_GetTime(&hrtc, &read_hours, &read_minutes, &read_seconds);
    if (status != HAL_OK) {
        // Handle error
    }
 
   uint8_t day = 11;
   uint8_t month = 5;
   uint8_t year = 23; 
   RTC_SetDate(&hrtc, day, month, year);
 
   uint8_t day;
   uint8_t month;
   uint8_t year;

   RTC_GetDate(&hrtc, &day, &month, &year);





    // Use the read hours, minutes and seconds values and the date values
    // ...

    while (1) {
        // Main loop
    }
}


```
