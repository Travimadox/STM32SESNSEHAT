# EEPROM Library Integration Guide

This guide provides instructions on how to integrate the EEPROM library into your STM32 project using STM32Cube IDE or any other compatible IDE.

## Step 1: Download the library files

Download the following EEPROM library files:

1. `EEPROM.h` - The header file containing the function prototypes and necessary definitions.
2. `EEPROM.c` - The source file containing the function implementations.

## Step 2: Add the library files to your project

Follow these steps to add the EEPROM library files to your project:

### STM32Cube IDE

1. In STM32Cube IDE, open your STM32 project.
2. Navigate to the project tree in the "Project Explorer" tab.
3. Place the `EEPROM.h` file into the "Inc" folder (or the folder where header files are stored in your project).
4. Place the `EEPROM.c` file into the "Src" folder (or the folder where source files are stored in your project).

### Other IDEs

1. Open your STM32 project in the IDE you are using.
2. Place the `EEPROM.h` file in the folder where header files are stored in your project (usually an "include" or "inc" folder).
3. Place the `EEPROM.c` file in the folder where source files are stored in your project (usually a "source" or "src" folder).

## Step 3: Include the library header in main.c

In the `main.c` file of your project, add the following include statement at the beginning of the file, along with other include statements:

```c
#include "EEPROM.h"
```

## Step 4: Usage Examples

ere are some examples of how to use the EEPROM library in your STM32 project:

### Write data to EEPROM
 ```c
 uint8_t data_to_write[] = "Hello, EEPROM!";
EEPROM_Write(0, 0, data_to_write, sizeof(data_to_write));
```

### Read data from EEPROM
```c
uint8_t read_buffer[16];
EEPROM_Read(0, 0, read_buffer, sizeof(read_buffer));
```

### Erase a page in EEPROM

```c
EEPROM_PageErase(2);
```

### COmprenhensive example on how to use it in main.c

```c
#include "main.h"
#include "EEPROM.h"

I2C_HandleTypeDef hi2c1;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    MX_GPIO_Init();
    MX_I2C1_Init();

    // Write data to EEPROM
    uint8_t data_to_write[] = "Hello, EEPROM!";
    EEPROM_Write(0, 0, data_to_write, sizeof(data_to_write));

    // Read data from EEPROM
    uint8_t read_buffer[16];
    EEPROM_Read(0, 0, read_buffer, sizeof(read_buffer));

    // Write a float number to EEPROM
    float number_to_write = 3.14159265;
    EEPROM_Write_NUM(1, 0, number_to_write);

    // Read a float number from EEPROM
    float read_number;
    read_number = EEPROM_Read_NUM(1, 0);

    // Erase a page in EEPROM
    EEPROM_PageErase(2);

    while (1)
    {
        // Main loop
    }
}

void SystemClock_Config(void)
{
    // System clock configuration code...
}

static void MX_GPIO_Init(void)
{
    // GPIO initialization code...
}

static void MX_I2C1_Init(void)
{
    // I2C1 initialization code...
}
```