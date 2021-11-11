// This #include statement was automatically added by the Particle IDE.
#include "Adafruit_GFX.h"

#include "Adafruit_LEDBackpack.h"

#define POT_PIN     A3

Adafruit_8x8matrix matrix1;
Adafruit_8x8matrix matrix2;

void displayTemp(int temp)
{
  char ones = temp % 10;
  char tens = temp / 10; // used to be modded by 10 after division, not sure what was the point of the mod operator

  matrix1.clear();
  matrix1.setCursor(0, 0);
  matrix1.write(tens + '0');
  matrix1.writeDisplay();

  matrix2.clear();
  matrix2.setCursor(0, 0);
  matrix2.write(ones + '0');
  matrix2.writeDisplay();
}

//void setupMatrix(Adafruit_8x8matrix *m)
void setupMatrix(void *mat)
{
  Adafruit_8x8matrix *m = (Adafruit_8x8matrix*) mat;
  m->clear();
  m->writeDisplay();
  m->setTextSize(1);
  m->setTextWrap(false);
  m->setTextColor(LED_ON);
  m->setRotation(0);
  m->setCursor(0, 0);
}

void setup() {
    matrix1.begin(0x70);
    matrix2.begin(0x71);
    
    setupMatrix(&matrix1);
    setupMatrix(&matrix2);
    
    pinMode(POT_PIN, INPUT);
}

void loop() {
    int inpot = analogRead(POT_PIN);
    //convert to a value between 0-99
    int out = 99 * inpot / 4095.0;
    
    // put the output on the desplay
    displayTemp(out);
}
