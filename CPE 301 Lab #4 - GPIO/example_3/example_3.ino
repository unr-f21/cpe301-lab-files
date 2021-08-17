// CPE 301 - REGISTER-LEVEL Blink Example
// Written By Frank Mascarich, Spring 2018

// Define Port B Register Pointers
volatile unsigned char* port_b = (unsigned char*) 0x25; 
volatile unsigned char* ddr_b  = (unsigned char*) 0x24; 
volatile unsigned char* pin_b  = (unsigned char*) 0x23; 

void setup() 
{
  //set PB7 to OUTPUT
  set_PB_as_output(7);
}

void loop() 
{
  // drive PB7 HIGH
  write_pb(7, 1);
  // wait 500ms
  delay(500);
  // drive PB7 LOW
  write_pb(7, 0);
  // wait 500ms
  delay(500);
}
void set_PB_as_output(unsigned char pin_num)
{
    *ddr_b |= 0x01 << pin_num;
}
void write_pb(unsigned char pin_num, unsigned char state)
{
  if(state == 0)
  {
    *port_b &= ~(0x01 << pin_num);
  }
  else
  {
    *port_b |= 0x01 << pin_num;
  }
}

