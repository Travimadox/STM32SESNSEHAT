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