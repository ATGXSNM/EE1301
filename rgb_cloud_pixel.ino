// This #include statement was automatically added by the Particle IDE.
#include <neopixel.h>
#include "Particle.h"


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

// This function will be called when someone calls the cloud_color cloud function
int setColorFromCloud(String input)
{
    if(input=="RED"){
        setLEDColor(0,255,255);
    }else if(input=="GREEN"){
        setLEDColor(255,0,255);
    }else if(input=="BLUE"){
        setLEDColor(255,255,0);
    }else if(input=="PURPLE"){
        setLEDColor(0,255,0);
    }else{
        // this function only accepts RED, GREEN, BLUE, or PURPLE
        return -1;
    }
    return 1;
}

void setup() {
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'

    // register cloud function cloud_color associated with program function setColorCloud
    Particle.function("cloud_color",setColorFromCloud);
    
    setLEDColor(128,0,255); // initialize the LED 
}

void loop() {
}
