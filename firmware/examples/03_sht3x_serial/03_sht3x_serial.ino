// Verified: SHT3X produced temperature and humidity readings over Serial.
// SHT3X VCC -> 5V (module tested at this supply), GND -> GND,
// SDA -> A4, SCL -> A5. Address on current module: 0x44.
#include <Wire.h>
#include <Adafruit_SHT31.h>
Adafruit_SHT31 sht31;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  if (!sht31.begin(0x44)) {
    Serial.println(F("SHT3X not found"));
    while (true) { delay(1000); }
  }
  Serial.println(F("SHT3X connected"));
}

void loop() {
  float t = sht31.readTemperature();
  float h = sht31.readHumidity();
  if (isnan(t) || isnan(h)) {
    Serial.println(F("Read failed"));
  } else {
    Serial.print(F("Temperature: "));
    Serial.print(t, 2);
    Serial.println(F(" C"));
    Serial.print(F("Humidity: "));
    Serial.print(h, 2);
    Serial.println(F(" %"));
    Serial.println(F("----------------"));
  }
  delay(2000);
}
