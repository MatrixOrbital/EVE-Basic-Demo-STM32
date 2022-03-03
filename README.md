# BASIC EVE2, EVE3 AND EVE4 TEST DEMO SOFTWARE for STM32

A quick and easy sanity check to ensure that your Matrix Orbital EVE2, EVE3 or EVE4 SPI TFT Display and touch hardware works properly.

This demo was developed on an STM32-Nucleo-F104RE but should easily transfer over to other variants

------------------------------------------------------------------

### Hardware Requirements:

![alt text](https://www.matrixorbital.com/image/cache/catalog/products/EVE/EVE3-43G-300x300.jpg)


**EVE4 SPI TFT** - Uses BT817/BT818 Graphics controller

https://www.matrixorbital.com/ftdi-eve/eve-bt817-bt818

**OR**

**EVE3 SPI TFT** - Uses BT815/BT816 Graphics controller

https://www.matrixorbital.com/ftdi-eve/eve-bt815-bt816

**OR**

**EVE2 SPI TFT** - Uses FT812/FT813 Graphics Controller

https://www.matrixorbital.com/ftdi-eve/eve-ft812

## INTERFACING

To interface the EVE display modules with the STM32-Nucleo there are two options:

### EVE2-SPI2BBC

An [EVE-SPI2BBC](https://www.matrixorbital.com/EVE-SPI2BBC) SPI to Bread Board Cable development Interface Kit w/ cable

This will work for most development kits and is the most flexible option to attach your EVE module to your MCU

<img src="https://www.matrixorbital.com/image/cache/catalog/products/EVE/EVE2%20Breakout%20Board-2-600x600.jpg" width="200" height="200">

Wiring diagram

|Nucleo|EVE Kit|
|------|-------|
|3.3V|3.3V|
|GND|GND|
|SCK/D13|SCK|
|MISO/D12|MISO|
|MOSI/D11|MOSI|
|PWM/CS/D10|RST|
|PWM/D9|CS|

### EVE2-SHIELD

An [EVE2-SHIELD](https://www.matrixorbital.com/eve2-shield) an arduino compatible shield.

<img src="https://www.matrixorbital.com/image/cache/catalog/products/EVE-Arduino-Shield-Scoodo-4-600x600.jpg" width="200" height="200">

(arduino not included)

NOTE: These will work with the STM Nucleo as long as external 5V power is provided on the VIN pin. 

## FIRMWARE

Clone this repository and open up the project in the [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)

Depending on the EVE module you have connected, you will need to make a small modification in `main.c` look for the call to `FT81x_Init` and adjust to parameters to fit your hardware. 

1. First Parameter : display size

|Display|Parameter|
|------|-------|
|[**29** - 2.9" 320 x 102 TFT](https://www.matrixorbital.com/eve2-29a)|DISPLAY_29
|[**35** - 3.5" 320 x 240 TFT](https://www.matrixorbital.com/index.php?route=product/search&search=eve3-35)|DISPLAY_35
|[**38** - 3.8" 480 x 116 TFT](https://www.matrixorbital.com/index.php?route=product/search&search=eve2-38)|DISPLAY_38
|[**39** - 3.9" 480 x 128 TFT](https://www.matrixorbital.com/index.php?route=product/search&search=eve3x-39)|DISPLAY_39
|[**43** - 4.3" 480 x 272 TFT](https://www.matrixorbital.com/index.php?route=product/search&search=eve3-43)|DISPLAY_43
|[**50** - 5.0" 800 x 480 TFT](https://www.matrixorbital.com/index.php?route=product/search&search=eve3-50)|DISPLAY_50
|[**52** - 5.2" 800 x 128 TFT](https://www.matrixorbital.com/index.php?route=product/search&search=eve3-52)|DISPLAY_52
|[**70** - 7.0" 800 x 480 TFT](https://www.matrixorbital.com/index.php?route=product/search&search=eve3-70)|DISPLAY_70

2. Second Parameter : EVE Module

|Generation|Parameter| 
|------|-------|
|EVE2|BOARD_EVE2|
|EVE3|BOARD_EVE3|
|EVE4|BOARD_EVE4|

3. Third Parameter: Touch screen

|Touch Panel Type|Parameter|
|------|-------|
|None|TOUCH_TPN|
|Resistive|TOUCH_TPR|
|Capcitive|TOUCH_TPC|

## RUN THE CODE

Once properly configured, click the Play button 

![Play](./Images/play.png)

If you have a touch screen, TPR or TPC, you will need to calibrate the touch screen by pressing the dots. After the calibration is complete, you will see Matrix Orbital with a blue circle. If you press the circle it will enlarge.

![alt text](https://raw.githubusercontent.com/MatrixOrbital/Basic-EVE-Demo/master/Screens/Basic-EVE-Demo-1.jpg)
![alt text](https://raw.githubusercontent.com/MatrixOrbital/Basic-EVE-Demo/master/Screens/Basic-EVE-Demo-2.jpg)
![alt text](https://raw.githubusercontent.com/MatrixOrbital/Basic-EVE-Demo/master/Screens/Basic-EVE-Demo-3.jpg)

** SUPPORT **

Support Forums: http://www.lcdforums.com/forums/viewforum.php?f=45
