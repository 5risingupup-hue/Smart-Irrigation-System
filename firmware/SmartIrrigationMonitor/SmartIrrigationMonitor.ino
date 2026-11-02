// Current verified subsystem: SHT3X (I2C) -> OLED + Serial.
// Buzzer on D8 was separately tested; no automatic alarm is enabled here.
// Libraries: Adafruit SHT31, Adafruit SSD1306, Adafruit GFX.

#include <Wire.h>
#include <Adafruit_SHT31.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SHT_ADDR 0x44
#define OLED_ADDR 0x3C
#define BUZZER_PIN 8

Adafruit_SHT31 sht31 = Adafruit_SHT31();
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Keep the active-high buzzer off (separately verified component).
  digitalWrite(BUZZER_PIN, LOW);
  pinMode(BUZZER_PIN, OUTPUT);

  if (!sht31.begin(SHT_ADDR)) {
    Serial.println(F("SHT3X ERROR!"));
    while (true) { delay(1000); }
  }
  if (!oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("OLED ERROR!"));
    while (true) { delay(1000); }
  }

  oled.clearDisplay();
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(1);
  oled.setCursor(0, 10);
  oled.println(F("SMART IRRIGATION"));
  oled.setCursor(0, 30);
  oled.println(F("System Ready!"));
  oled.display();
  Serial.println(F("System Ready!"));
  delay(1500);
}

void loop() {
  const float temperature = sht31.readTemperature();
  const float humidity = sht31.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println(F("Sensor Read Failed!"));
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setCursor(0, 16);
    oled.println(F("Sensor Error!"));
    oled.display();
    delay(2000);
    return;
  }

  Serial.print(F("Temperature: "));
  Serial.print(temperature, 1);
  Serial.println(F(" C"));
  Serial.print(F("Humidity: "));
  Serial.print(humidity, 1);
  Serial.println(F(" %"));

  oled.clearDisplay();
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(1);
  oled.setCursor(0, 0);
  oled.println(F("SMART IRRIGATION"));
  oled.drawLine(0, 12, 127, 12, SSD1306_WHITE);

  oled.setCursor(0, 19);
  oled.println(F("Temperature:"));
  oled.setTextSize(2);
  oled.setCursor(0, 30);
  oled.print(temperature, 1);
  oled.println(F(" C"));

  oled.setTextSize(1);
  oled.setCursor(0, 54);
  oled.print(F("Humidity: "));
  oled.print(humidity, 1);
  oled.print(F("%"));
  oled.display();
  delay(2000);
}
