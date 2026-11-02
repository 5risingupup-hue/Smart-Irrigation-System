// Verified separately with an active-high buzzer module.
// VCC -> 5V, GND -> GND, I/O -> D8.
const int BUZZER_PIN = 8;
void setup() {
  digitalWrite(BUZZER_PIN, LOW);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(200);
  digitalWrite(BUZZER_PIN, LOW);
  delay(1000);
}
