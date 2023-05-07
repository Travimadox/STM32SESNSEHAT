# TMP102 Library Integration Guide

This guide provides instructions on how to integrate the TMP102 temperature sensor library into your STM32 project using STM32Cube IDE or any other compatible IDE.

## Step 1: Download the library files

Download the following TMP102 library files:

1. `tmp102.h` - The header file containing the function prototypes and necessary definitions.
2. `tmp102.c` - The source file containing the function implementations.

## Step 2: Add the library files to your project

Follow these steps to add the TMP102 library files to your project:

### STM32Cube IDE

1. In STM32Cube IDE, open your STM32 project.
2. Navigate to the project tree in the "Project Explorer" tab.
3. Place the `tmp102.h` file into the "Inc" folder (or the folder where header files are stored in your project).
4. Place the `tmp102.c` file into the "Src" folder (or the folder where source files are stored in your project).

### Other IDEs

1. Open your STM32 project in the IDE you are using.
2. Place the `tmp102.h` file in the folder where header files are stored in your project (usually an "include" or "inc" folder).
3. Place the `tmp102.c` file in the folder where source files are stored in your project (usually a "source" or "src" folder).

## Step 3: Include the library header in main.c

In the `main.c` file of your project, add the following include statement at the beginning of the file, along with other include statements:

```c

#include "tmp102.h"
```
## Step 4: Initialize the I2C interface

Before using the TMP102 sensor, you need to initialize the I2C interface. This can be done using the `HAL_I2C_Init()` function provided by the STM32 HAL library. Here's an example:

```c

I2C_HandleTypeDef hi2c1;

void SystemClock_Config(void);

int main(void) {
  // Initialize HAL and system clock
  HAL_Init();
  SystemClock_Config();

  // Initialize I2C1
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x00707CBB;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK) {
    Error_Handler();
  }
}
```

## Step 5: Initialize the TMP102 sensor and read Temperature Value
After initializing the I2C interface, you can now initialize the TMP102 sensor. This can be done using the TMP102_Init() function provided by the library. Here's an example:

```c

#include "tmp102.h"

I2C_HandleTypeDef hi2c1;

int main(void)
{
  HAL_Init();
  MX_I2C1_Init();
  
  // Initialize TMP102 sensor
  TMP102_Init(&hi2c1);//Use the I2C handle intiliased
  while (1)
  {
    // Read temperature value
    float temperature = TMP102_ReadTemperature(&hi2c1);
    
    // Do something with temperature value
  }
}

  ```

  








