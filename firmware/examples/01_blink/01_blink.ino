// Verified: the Arduino UNO onboard LED blinked successfully.
// Pin LED_BUILTIN is D13 on Arduino UNO R3.
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
