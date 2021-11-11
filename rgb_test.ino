#define RED_PIN     A4
#define GREEN_PIN   A5
#define BLUE_PIN    A6

#define MODE_PIN    D2

void setLEDColor(uint8_t red, uint8_t green, uint8_t blue)
{
    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, green);
    analogWrite(BLUE_PIN, blue);
}

void setup() {
    pinMode(MODE_PIN, INPUT_PULLUP);
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
    
    setLEDColor(0,0,0);
}

void loop() {

    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(0,255,255);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(255,0,255);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(255,255,0);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(0,0,255);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(0,255,0);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(255,0,0);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(0,128,255);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(0,255,128);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(128,0,255);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(255,0,128);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(128,255,0);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(255,128,0);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(0,0,0);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(32,32,0);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(64,64,0);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(96,96,0);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(128,128,0);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(160,160,0);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(192,192,0);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(224,224,0);
    delay(500);
    //while(digitalRead(MODE_PIN) == HIGH);
    setLEDColor(255,255,0);
    delay(500);
}
