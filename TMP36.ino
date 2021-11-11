// This #include statement was automatically added by the Particle IDE.
#include "adafruit-led-backpack/adafruit-led-backpack.h"

//#include "Adafruit_LEDBackpack.h"
//TMP36 Pin Variables
#define sensorPin A0 //the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade with a
                        //500 mV offset to allow for negative temperatures

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

/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup()
{
    matrix1.begin(0x70);
    matrix2.begin(0x71);
    
    setupMatrix(&matrix1);
    setupMatrix(&matrix2);
    Serial.begin(9600);  //Start the serial connection with the computer
                       //to view the result open the serial monitor 
    pinMode(sensorPin,INPUT);
}
 
void loop()                     // run over and over again
{
 //getting the voltage reading from the temperature sensor
 int reading = analogRead(sensorPin); 
 
 // converting that reading to voltage, for 3.3v arduino use 3.3
 //float temperatureF = reading * 0.14505494505495 - 58;
 float temperatureC = -40 + (reading-124.1)/12.41; 

 //displayTemp(temperatureF);
 //Serial.println(temperatureF);
 displayTemp(temperatureC);
 Serial.println(temperatureC);

 delay(1000);                                     //waiting a second
}
