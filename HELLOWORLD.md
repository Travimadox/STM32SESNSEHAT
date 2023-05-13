# STM32 ENVIRONSENSING HAT: Hello World Version

This program is designed to read data from temperature sensors and an analog light sensor, timestamp the data, and transmit it over UART to a terminal.

## Hello World Set Up Instructions

### Step 1: Hardware and Software Setup
For an in-depth guide on how to setup your hardware and software, kindly visit this link: [Setup Guide](SESNSEHATSETUP.md).

### Step 2: Download the HelloWorld Drivers
You can find and download the necessary HelloWorld drivers for this project from the following link: [HelloWorldDrivers](https://github.com/Travimadox/STM32SESNSEHAT/blob/main/Firmware/SENSEHATHELLOWORLD.zip)

### Step 3: Import the Project into STM32 CubeIDE
If you're unsure of how to import the project, refer to the following guides:
- [Imperium: Importing projects into STM32CubeIDE workspace - Step 3](https://github.com/Travimadox/STM32SESNSEHAT/blob/main/SESNSEHATSETUP.md)
- [Fastbitlab: Importing projects into STM32CubeIDE workspace](https://fastbitlab.com/microcontroller-embedded-c-programming-importing-projects-in-to-stm32cubeide-workspace/)

### Step 4: Build, Debug, and Flash the Project
Build and debug the project, then flash it onto the microcontroller. Remember to set the time and date at the beginning.

### Step 5: Setup Software Terminal Emulator
Open your software terminal emulator and ensure the settings match the UART settings in the hello world project. When everything is set up correctly, you should see output resembling the one below:

![Hello World Output](https://imgur.com/Geee6TX.jpg)
