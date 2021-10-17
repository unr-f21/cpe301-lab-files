# CPE 301 Embedded Systems Design LAB 8 

## Topic: Analog to Digital Conversion

## Objective

To learn how to program the ATmega Analog to Digital Converters by initializing and using the appropriate special function registers. You will develop two functions, *adc_init*, and *adc_read*, and a program which uses the two functions to read analog data from a photoresistor and sends the data over serial to a PC. 

## Before the Lab
Download the Atmel datasheet for the 2560 from WebCampus or from [here](https://ww1.microchip.com/downloads/en/devicedoc/atmel-2549-8-bit-avr-microcontroller-atmega640-1280-1281-2560-2561_datasheet.pdf).

Review the following sections of the datasheet to get generally familiar with the operations and registers that will be needed for the lab.
- 26.2
- 26.3
- 26.4
- 26.8. 

Review section 13.2 in Mazidi. 

 

## Procedure
1\.Write two ANSI C functions:

- `void adc_init( )` – Initializes the Analog to Digital Converter to be ready to read analog data.

- `unsigned int adc_read(unsigned char adc_channel)` – Returns the analog data read from the analog channel given as a parameter. 

2\.Connect a photoresistor and an axial resistor in series as a voltage divider and write a program which reads the analog voltage of the divider and sends the voltage values over serial to your PC. Use the Arduino IDE’s Serial Plotter to plot the voltage values.

3\. Modify the program to turn on the on-board LED when the light level is above some threshold. 

## What to Turn In

- During the lab session, demonstrate your code to the TA. 
- Add your name and your lab partner's name to the top of each of your ino files as comments.
- In WebCampus, turn in your .ino files. *All lab partners must turn in the assignment to WebCampus to get credit for the lab*.

