# 1. Setting up an ADC Channel in STM32CubeIDE:

Follow these steps to set up an ADC channel for your project in STM32CubeIDE:

1. Open your project in STM32CubeIDE.
2. Click on the "Pinout & Configuration" tab, usually located at the bottom of the window.
3. Navigate to the "Analog" section in the left-hand menu.
4. Locate "ADC" and expand its options.
5. Select "Channel 5" and set the ADC mode to "Continuous Conversion Mode".
6. Save your configuration and generate the code.

For reference, you can refer to the image below, which shows the STM32CubeIDE interface with the proper ADC configuration:

![STM32CubeIDE ADC Configuration](https://i.imgur.com/Jzra9d8.jpg)

# 2. Setting up an I2C Channel in STM32CubeIDE:
## Setting up I2C channel
Follow these steps to set up an I2C channel for your project in STM32CubeIDE:

1. Open your project in STM32CubeIDE.
2. Click on the "Pinout & Configuration" tab, usually located at the bottom of the window.
3. Navigate to the "Connectivity" section in the left-hand menu.
4. Locate "I2C" and expand its options.
5. Enable I2C from the dropdown menu on the right.
6. For reference, you can refer to the image below:

![STM32CubeIDE I2C Configuration](https://imgur.com/oSr9DWS.jpg)

## Setting up System clock
Follow these steps to set up the system clock

1. Open your project in STM32CubeIDE.
2. Click on the "Pinout & Configuration" tab, usually located at the bottom of the window.
3. Navigate to the "System Core" section in the left-hand menu.
4. Locate "RCC" and expand its options then select High Speed Clock and choose source as Crystal Ceramic Oscillator.
5. For reference, you can refer to the image below:


![STM32CubeIDE System Clock Configuration](https://imgur.com/IcynAkS.jpg)


# 4.Setting up RTC peripherals in STM32CubeIDE

## Setting up System clock
Follow these steps to set up the system clock

1. Open your project in STM32CubeIDE.
2. Click on the "Pinout & Configuration" tab, usually located at the bottom of the window.
3. Navigate to the "System Core" section in the left-hand menu.
4. Locate "RCC" and expand its options then select High Speed Clock and Low Speed Clock then choose source as Crystal Ceramic Oscillator.
5. For reference, you can refer to the image below:

![STM32CubeIDE System Clock Configuration](https://imgur.com/fCryHur.jpg)

## Setting the RTC Timer
Follow these steps to set up the RTC Timer:

1. Open your project in STM32CubeIDE.
2. Click on the "Pinout & Configuration" tab, usually located at the bottom of the window.
3. Navigate to the "Timers" section in the left-hand menu.
4. Locate "RTC" and expand its options then Activate clock source and calendar. No need to set the date and time as this catered for by the library functions.
5. For reference, you can refer to the image below:

![STM32CubeIDE RTC TIMER Configuration](https://imgur.com/ctcmJdC.jpg)


## Clock Configuration
Change the HCLK to 48MHz as shown below:

![STM32CubeIDE Clock Configuration](https://imgur.com/e8fyvbw.jpg)

