# neopixel color selector

Select colors of a strip of neopixels based on the HSV color wheel using a joystick. Note the arduino joystick is simulated here just using two pots (see https://www.arduino.cc/en/Tutorial/JoyStick).

You press the button on the joystick and the LEDs glow with the color selected corresponding to the position of the joystick relative to a HSV color wheel (see [library documentation](https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use#hsv-hue-saturation-value-colors-dot-dot-dot-17-41))

online simulation in tinkercad circuit
https://www.tinkercad.com/things/4E4PenrSsq7


# Costume application

You could use this for a variety of things, but I actually used it to light neopixels LEDs in a eyes of a costume, I could press the button and the eyes would glow. I glued neopixels to the eyes, and ran cat5 cable down to my hand where I held the joystick, arduino nano, and a 9v battery.

![](clown_costume_lighted_eyes.jpg)