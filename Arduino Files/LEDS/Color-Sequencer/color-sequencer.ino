int led_count = 5;
int ledArr[] = {13,12,11,10,9};
int currState[] = {HIGH, LOW, LOW, LOW, LOW};
int currHighLED = 0;

void setup() {
  for(int i = 0; i < led_count; i++) {
    pinMode(ledArr[i], OUTPUT);
  }
}

void loop() {
  for(int i = 0; i < led_count; i++) {
    digitalWrite(ledArr[i], currState[i]);
  }
  
  currState[currHighLED] = LOW;
  currHighLED++;

  if(currHighLED >= 5) {
    currHighLED = 0;
  }

  currState[currHighLED] = HIGH;
  delay(500);
}
