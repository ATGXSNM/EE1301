#include "Particle.h"
#include "neopixel.h"

SYSTEM_MODE(AUTOMATIC);

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D4
#define PIXEL_COUNT 1
#define PIXEL_TYPE WS2811

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setLEDColor(uint8_t red, uint8_t green, uint8_t blue)
{
    int newColor = strip.Color(255-red, 255-green, 255-blue);
    strip.setPixelColor(0, newColor);
    strip.show();
}


// This version of the code works with the Neopixel RGB LED that is in your kit

void setup()
{
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
}

void loop()
{
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(0,255,255);
    delay(1500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(255,0,255);
    delay(1000);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(255,255,0);
    delay(1000);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(0,0,255);
    delay(1000);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(0,255,0);
    delay(1000);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(255,0,0);
    delay(1000);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(0,128,255);
    delay(1000);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(0,255,128);
    delay(1000);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(128,0,255);
    delay(1000);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(255,0,128);
    delay(1000);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(128,255,0);
    delay(1000);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(255,128,0);
    delay(1000);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(0,0,0);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(32,32,32);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(64,64,64);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(96,96,96);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(128,128,128);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(160,160,160);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(192,192,192);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(224,224,224);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(255,255,255);
    delay(500);
}
