uint8_t period_ms[] = {5, 10, 20, 50};
uint8_t current_period = 0;

void setup() {
pinMode(2, INPUT_PULLUP);
pinMode(3, INPUT_PULLUP);
pinMode(4, INPUT_PULLUP);
pinMode(5, INPUT_PULLUP);

pinMode(13, OUTPUT);
}

void loop() {
  if(!digitalRead(2))
  {
    current_period = period_ms[0];
  }
  else if(!digitalRead(3))
  {
    current_period = period_ms[1];
  }
  else if(!digitalRead(4))
  {
    current_period = period_ms[2];
  }
  else if(!digitalRead(5))
  {
    current_period = period_ms[3];
  }
  digitalWrite(13, HIGH);
  delay(current_period);
  digitalWrite(13, LOW);
  delay(current_period);
}
