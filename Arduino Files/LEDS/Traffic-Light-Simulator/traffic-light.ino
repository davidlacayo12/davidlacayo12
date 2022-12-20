int GREEN = 2;
int BLUE = 3;
int RED = 4;
int DELAY_GREEN = 5000;
int DELAY_BLUE = 2000;
int DELAY_RED = 5000;

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);

}

void loop() {
  green_light();
  delay(DELAY_GREEN);
  blue_light();
  delay(DELAY_BLUE);
  red_light();
  delay(DELAY_RED);
}

void green_light() {
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, LOW);
  digitalWrite(RED, LOW);
}

void blue_light() {
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);
  digitalWrite(RED, LOW);
}

void red_light() {
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(RED, HIGH);
}
