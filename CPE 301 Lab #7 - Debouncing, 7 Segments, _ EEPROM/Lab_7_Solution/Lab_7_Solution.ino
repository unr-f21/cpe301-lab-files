/*
 * CPE 301 Lab 7 Solution
 * Debouncing, 7-Segments, EEPROM
 * Written By Frank Mascarich, Fall 2018
 * This program counts the presses of a button and displays the counts on
 * a 7-segment display (displays 0 thru F). The counter variable is also stored and read back from
 * EEPROM memory at boot time. 
 */


#define COUNTER_EEPROM_ADDRESS  0x0025

// this is the character array, mapped such that the first element displays a '0' on the 7-segment
unsigned char chr_array[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7C, 0x07, 0x7F, 0x67, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

// make some pointers to port k (the 7 segment register)
volatile unsigned char* ddr_k  = (unsigned char*) 0x107;
volatile unsigned char* port_k = (unsigned char*) 0x108;
volatile unsigned char* pin_k  = (unsigned char*) 0x106;

// make some pointers to port f (the button - PF7)
volatile unsigned char* ddr_f  = (unsigned char*) 0x30;
volatile unsigned char* port_f = (unsigned char*) 0x31;
volatile unsigned char* pin_f  = (unsigned char*) 0x2F;

// make some pointers to the EEPROM registers
volatile unsigned int*  EEPROM_ADDR_REG  = (unsigned int*) 0x41;
volatile unsigned char* EEPROM_DATA_REG  = (unsigned char*) 0x40;
volatile unsigned char* EEPROM_CNTRL_REG = (unsigned char*) 0x3F;

// make a counter variable to track our current character
unsigned char counter = 0;

void setup() 
{
  // set PF7 to input
  *ddr_f &= 0x7F;
  // enable PF7 pullup 
  *port_f |= 0x80;

  // set PK0:6 to output
  *ddr_k |= 0x7F;

  // read the counter from EEPROM
  counter = eeprom_read(COUNTER_EEPROM_ADDRESS);
  // if the counter is > 15, reset it to 0
  counter %= 16;
  // initialize display to whatever we read...
  display_num(counter);
}
void loop() 
{
  // if PF7 is Low
  if(!(*pin_f & 0x80))
  {
      // wait just a bit
      for(volatile unsigned int i = 0; i < 1000; i++);
      // if PF7 is still low
      if(!(*pin_f & 0x80))
      {
        // increment the counter
        counter++;
        // make sure it stays between 0 and 15
        counter %= 16;
        // display the counter
        display_num(counter);
        // save the counter to memory
        eeprom_write(COUNTER_EEPROM_ADDRESS, counter);
        // wait for the pin to go back high
        while(!(*pin_f & 0x80));
      }
  }
}
void display_num(unsigned char num)
{
  // note that this actually assigns PK0:7... should only assign PK0:6
  *port_k = ~chr_array[num];
}
void eeprom_write(unsigned int address, unsigned char data_in)
{
  /* Wait for completion of previous write */
  while(*EEPROM_CNTRL_REG & 0x02);
  /* Set up address and Data Registers */
  *EEPROM_ADDR_REG = address;
  *EEPROM_DATA_REG = data_in;
  /* Write logical one to EEMPE */
  *EEPROM_CNTRL_REG |= 0x04;
  /* Write logical zero to EEPE */
  *EEPROM_CNTRL_REG &= ~(0x02);
  /* Write logical one to EEPE */
  *EEPROM_CNTRL_REG |= 0x02;
}
unsigned char eeprom_read(unsigned int address)
{
  /* Wait for completion of previous write */
  while(*EEPROM_CNTRL_REG & 0x02);
  /* Set up address register */
  *EEPROM_ADDR_REG = address;
  /* Start eeprom read by writing EERE */
  *EEPROM_CNTRL_REG |= 0x01;
  /* Return data from Data Register */
  return *EEPROM_DATA_REG;
}








