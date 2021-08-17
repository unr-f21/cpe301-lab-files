// CPE 301 - REGISTER-LEVEL Blink Example
// Written By Frank Mascarich, Spring 2018

#define WRITE_HIGH_PB(pin_num)  *port_b |= (0x01 << pin_num);
#define WRITE_LOW_PB(pin_num)  *port_b |= ~(0x01 << pin_num);

// Define Port B Register Pointers
volatile unsigned char* port_b = (unsigned char*) 0x25; 
volatile unsigned char* ddr_b  = (unsigned char*) 0x24; 
volatile unsigned char* pin_b  = (unsigned char*) 0x23; 

void setup() 
{
  //set PB7 to OUTPUT
  *ddr_b |= 0x80;
}

void loop() 
{
  // drive PB7 HIGH
  WRITE_HIGH_PB(7);
  // wait 500ms
  delay(500);
  // drive PB7 LOW
  WRITE_LOW_PB(7);
  // wait 500ms
  delay(500);
}
