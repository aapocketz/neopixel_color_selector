#include <Adafruit_NeoPixel.h>
#include <math.h>

const int LED_PIN = 6;
const int LED_COUNT = 2;
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
const uint8_t MAX_BRIGHTNESS = 255;
uint8_t brightness = 0;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  strip.begin();
  strip.setBrightness(MAX_BRIGHTNESS);
  strip.show();
}

void loop() {
  bool pressed = (digitalRead(SW_pin) == LOW) ? true : false;

  if (pressed and brightness < MAX_BRIGHTNESS) {
    brightness += 1;
  }
  if (not pressed and brightness > 0) {
    brightness -= 1;
  }
  double x = (analogRead(X_pin) - 512) / 512.0;
  double y = (analogRead(Y_pin) - 512) / 512.0;

  // polar conversion
  double r = sqrt(x * x + y * y);
  double phi = atan2(y, x);

  // hue saturation conversion
  uint16_t hue = (phi / (2 * M_PI)) * 65535;
  uint8_t saturation = r * 255;
  uint32_t rgbcolor = strip.ColorHSV(hue, saturation, brightness);
  strip.fill(rgbcolor);
  strip.show();
  delay(10);
}