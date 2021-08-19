volatile unsigned char *myTCCR1A = (unsigned char *) 0x80;
volatile unsigned char *myTCCR1B = (unsigned char *) 0x81;
volatile unsigned char *myTCCR1C = (unsigned char *) 0x82;
volatile unsigned char *myTIMSK1 = (unsigned char *) 0x6F;
volatile unsigned int  *myTCNT1  = (unsigned  int *) 0x84;
volatile unsigned char *myTIFR1 =  (unsigned char *) 0x36;
volatile unsigned char *portDDRB = (unsigned char *) 0x24;
volatile unsigned char *portB =    (unsigned char *) 0x25;

unsigned char in_char = 'z';
unsigned int current_freq = 0;
unsigned char letters[] = {'a', 'A', 'b', 'c', 'C', 'd', 'D', 'e', 'f', 'F', 'g', 'G', 'q'};
unsigned int freq_array[] = {440, 446, 494, 523, 554, 587, 624, 659, 698, 740, 784, 831, 0};


void setup() 
{
  // set PB6 to output
  *portDDRB |= 0x40;
  // Initialize PB6 to low
  *portB &= 0xBF;
  // init timer control registers
  *myTCCR1A = 0x00;
  *myTCCR1B = 0x00;
  *myTCCR1C = 0x00;
  Serial.begin(9600);
}
void loop() 
{
  if(Serial.available())
  {
    in_char = Serial.read();
    //Serial.println(in_char);
    //current_freq = 0;
    for(int i = 0; i < 13; i++)
    {
      if(in_char == letters[i])
      {
        current_freq = freq_array[i];
        break;
      }
    }
  }
  if(current_freq != 0)
  {
    // set it high
    *portB |= 0x40;
    // wait
    my_delay(current_freq);
    // set it low
    *portB &= 0xBF;
    // wait
    my_delay(current_freq);
  }
  else
  {
    // set it low
    *portB &= 0xBF;
  }
}
void my_delay(unsigned int freq)
{
  // calc period
  double period = 1.0/double(freq);
  // 50% duty cycle
  double half_period = period/ 2.0f;
  // clock period def
  double clk_period = 0.0000000625;
  // calc ticks
  unsigned int ticks = half_period / clk_period;
  // stop the timer
  *myTCCR1B &= 0xF8;
  // set the counts
  *myTCNT1 = (unsigned int) (65536 - ticks);
  // start the timer
  * myTCCR1B |= 0b00000001;
  // wait for overflow
  while((*myTIFR1 & 0x01)==0); // 0b 0000 0000
  // stop the timer
  *myTCCR1B &= 0xF8;   // 0b 0000 0000
  // reset TOV           
  *myTIFR1 |= 0x01;
}

