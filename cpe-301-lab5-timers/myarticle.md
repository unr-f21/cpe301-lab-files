# CPE 301 Embedded Systems Design Lab #05

## Objective

To become familiar with the use of timers in computer applications.  Specifically, to implement a piano like keyboard program using the ATmega2560 timer1 in Normal mode and an external speaker.

## Before the Lab
Download the Atmel datasheet for the 2560 from WebCampus or from [here](https://ww1.microchip.com/downloads/en/devicedoc/atmel-2549-8-bit-avr-microcontroller-atmega640-1280-1281-2560-2561_datasheet.pdf).

Review the following sections of the datasheet to get generally familiar with the operations and registers that will be needed for the lab.

- 16-Bit Timer Description – 17.2, Page 133
- Normal Mode Description – 17.1.9, Page 145
- Register Description – 17.11, Page 154
- Clock Select – 17.11.8, Page 157
- Prescalers – 18, Page 164

## Procedure

1\. Write a C program for the Arduino which will monitor the keyboard for inputs of A, B, C, D, E, F, and G. Depending upon which key was pressed **use the timer** to generate a square wave on PortB.6 of the ATmega2560 (Arduino Digital pin 12) of the appropriate frequency for the based on the table below. The note should last until another key is pressed, at which time the new note will be played.  If the 'q' key is pressed the note should stop playing. For debugging purposes, use of the Arduino Serial Library is permitted for this lab.  Use the file `serial_echo_example.ino` as an example of serial I/O.

Your program must contain a function which takes the frequency as an input, and then configures and runs the timer. This function must work for all notes listed in the table. It does not have to work for all possible frequencies. 

| Note | Frequency Hz|
|:----:|:---------:|
|  A   |    440    |
|  B   |    494    |
|  C   |    523    |
|  D   |    587    |
|  E   |    659    |
|  F   |    698    |
|  G   |    784    |

2\. Connect the lab speakers to PortB.6 and ground so that you can hear the output. 
**The output of the Arduino port must be connected to the speaker through a resistor. The speaker is 8 Ohms, so connecting it directly will cause too much current to be supplied by the Arduino, possibly damaging it.**

> Be sure to always disconnect Arduino power before connecting or
disconnecting anything else to it

3\. Use the oscilloscope to measure the frequency of each note. Make a table such as the one below that shows the target frequency and the actual frequency that you achieved. If the values are not exact, what do you think might cause the discrepancy?

| Note | Target Frequency Hz| Measured Frequency|
|:----:|:---------:|:---------:|
|  A   |    440    ||
|  B   |    494    ||
|  C   |    523    ||
|  D   |    587    ||
|  E   |    659    ||
|  F   |    698    ||
|  G   |    784    ||





