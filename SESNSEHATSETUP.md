# Setting up the SENSEHAT for the first time.
## Requirements:
### 1.Hardware Requirements
To work with this repository, you will need the following hardware:

1. STM32SenseHat
2. STM32F051C6T6 Daughter Board
3. USB-A to Micro-USB cable
4. 4.2V 18650 Li-Ion battery
5. ST-LINK V2

Please ensure that you have all the necessary hardware before proceeding with the setup.


### 2.Software Requirements
The code in this repository has primarily been developed using the STM32CubeIDE. This is the recommended IDE for working with this codebase.

**Recommended IDE**: 

- STM32CubeIDE

However, the repository is also compatible with several other IDEs. If you are comfortable using an alternative IDE, please make sure to install the necessary plugins and extensions.

**Alternative IDEs**:

- Visual Studio Code: 
  You will need the following plugins:
    - [STM32 for VSCode by Bureau Moeilijke Dingen](https://marketplace.visualstudio.com/items?itemName=bmd.stm32-for-vscode)
    - [STM32 by STMicroelectronics](https://marketplace.visualstudio.com/items?itemName=stmicroelectronics.stm32-vscode-extension)
    
- Keil MicroVision: 
  You can download it [here](https://www.keil.com/)
  **Note**: This is a paid IDE,however a free version is also available.

Please note, the codebase is written in C. However, contributions in C++ or Embedded Rust are welcome.

**Software terminal emulator**

The examples provided here are based on the Tera Term ,however the other software terminal emulators should work too.
- Tera Term 
- Real Term
- PuTTY
- OpenSSH
- KiTTY

## Setting up STM32 Peripherals:
To set up the STM32 peripherals check:[Setting up STM32 peripherals](https://github.com/Travimadox/STM32SESNSEHAT/blob/main/Firmware/STM32SETUP.md)


## STEP1. Powering and setting up the SENSEHAT hardware.
**CAUTION:** Ensure that the power source supplies at least 5V at 1A.

Follow this steps to set up you SENSEHAT.

  1. Connect the power source to the HAT via the USB cable.The LED should go on to indicate it is on.
  2. Place the 18650 battery in the battery holder and Let the battery charge for an hour, the green LED will go on when fully charged.
  3. Unplug the power supply and plug in the STM32F0 to the SENSEHAT as shown below.
  
  ![Connecting_STM32F0_to_SENSEHAT](https://imgur.com/jDwVCAp.jpg)
  
## Step2. Include libraries to the SENSEHAT.
  1. Download and include the LDR files by following this [instructions](https://github.com/Travimadox/STM32SESNSEHAT/tree/main/Firmware).
  2. Download and include the TMP102 (temperature sensor) [files](https://github.com/Travimadox/STM32SESNSEHAT/tree/main/Firmware/TMP102) by following this [instructions](https://github.com/Travimadox/STM32SESNSEHAT/blob/main/Firmware/TMP102/Instructions.md).
  3. Download the [LTR303ALS file](https://github.com/Travimadox/STM32SESNSEHAT/tree/main/Firmware/LTR303ALS) and follow this [instruction](https://github.com/Travimadox/STM32SESNSEHAT/blob/main/Firmware/LTR303ALS/Instructions.md) to include them in your project.
  4. Download and include the RTC [files](https://github.com/Travimadox/STM32SESNSEHAT/tree/main/Firmware/RTC) by following this [instructions](https://github.com/Travimadox/STM32SESNSEHAT/blob/main/Firmware/RTC/Instructions.md).
  5. Download and include the AT24C256 (EEPROM) [files](https://github.com/Travimadox/STM32SESNSEHAT/tree/main/Firmware/AT24C256) by following this [instructions](https://github.com/Travimadox/STM32SESNSEHAT/blob/main/Firmware/AT24C256/Instructions.md).
## Step3: Test the Libraries(Optional).
  1. Download test [files](https://github.com/Travimadox/STM32SESNSEHAT/blob/main/Firmware/SENSEHATLIBTESTS.zip).
  2. Copy the file directory.
  
  ![Copying directory](https://imgur.com/flXyq9m.jpg)
  
  3. Go to file in the STM32cubeIDE, select "Open projects from file system".
  
  ![Opening project](https://imgur.com/aRxXnUd.jpg)
  
  4. In the open dialogue, paste the file directory in the "import source" block.
  
  ![Pasting file directory](https://imgur.com/NZ3Mk1j.jpg)
  5. Expand the Libraries folder>>SENSEHATEEPROMTEST>>core>>Src then open the main.c file.
  
  ![Opening main.c file](https://imgur.com/gXpqbmc.jpg)
  
  6. Run the code!
  7. Follow the steps **2-to-6** above to test for other libraries.

## Step 4: Implementation of Sensehat Full Functionality
**Still being worked on**
  1. Connect the SENSEHAT to the PC via a USB cable. The debugger light should go on as shown below.
  
  ![Debugger](https://imgur.com/ZuuBLmn.jpg)
  
  2. Download the intergrating drivers here: [STM32SenseHatDriver](https://github.com/Travimadox/STM32SESNSEHAT/tree/main/Firmware/SENSEHAT).
  3. Open the files in STM32cubeIDE by following steps 2-to-5 in `Step3` above.
  4. Build and run the main.c file. You should see the debugger light flashing, wait till the following displays in console.
  
  ![Exit_message](https://imgur.com/2vOc9Pu.jpg).
  
  5. Your SENSEHAT is now ready! You can disconnect and place it in the environment of you choice.

# FAQ
**Video to be uploaded soon**

Should you encounter problems while setting up your SENSEHAT, please visit our [FAQ](FAQ.md) or alternately watch the video on [How to setup SENSEHAT]().
