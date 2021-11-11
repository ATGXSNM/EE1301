// This #include statement was automatically added by the Particle IDE.
#include "adafruit-led-backpack/adafruit-led-backpack.h"

#define POT_PIN     A3

int button = D2;                      // button is connected to D2
bool prev_button_state = false;
bool curr_button_state = false;

Adafruit_8x8matrix matrix1;
Adafruit_8x8matrix matrix2;

// declare program variable to be assiciated with cloud variable
int out;

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
    pinMode(button, INPUT_PULLDOWN);    // sets pin as input
    
    Serial.begin(9600);
}

void loop() {
    
    // sample the potentiometer
    int inpot = analogRead(POT_PIN);
    //convert to a value between 0-99
    out = 99 * inpot / 4095.0;  

    // Sample the potentiometer if the button is pressed
    curr_button_state = digitalRead(button);
    if(curr_button_state == true && prev_button_state == false) {
        delay(40); // debouncing
        prev_button_state = true;
        
        // publish an event notifying subscribers that button was pressed
        // include potentiometer sample as the event's data
        Particle.publish("buttonPress_event_yourX500", String(out));
    } else if(curr_button_state == false){
        prev_button_state = false;
    }
    
    // put the output sample on the desplay
    displayTemp(out);
    Serial.println(out);
    
    delay(100); // only publish events at a max rate of 1/second
}
