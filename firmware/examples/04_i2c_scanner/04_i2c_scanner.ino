// Verified I2C scan: OLED 0x3C and SHT3X 0x44.
#include <Wire.h>
void setup() {
  Serial.begin(9600);
  Wire.begin();
  Serial.println(F("I2C Scanner Started"));
}
void loop() {
  byte count = 0;
  Serial.println(F("Scanning..."));
  for (byte address = 1; address < 127; ++address) {
    Wire.beginTransmission(address);
    const byte error = Wire.endTransmission();
    if (error == 0) {
      Serial.print(F("Device found at 0x"));
      if (address < 16) Serial.print('0');
      Serial.println(address, HEX);
      ++count;
    }
  }
  Serial.print(F("Total devices: "));
  Serial.println(count);
  Serial.println(F("----------------"));
  delay(3000);
}
