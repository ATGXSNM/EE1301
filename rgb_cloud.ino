#define RED_PIN     A4
#define GREEN_PIN   A5
#define BLUE_PIN    A6

void setLEDColor(uint8_t red, uint8_t green, uint8_t blue)
{
    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, green);
    analogWrite(BLUE_PIN, blue);
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
    }else{
        // this function only accepts RED, GREEN, or BLUE
        return -1;
    }
    return 1;
}

void setup() {
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);

    // register cloud function cloud_color associated with program function setColorCloud
    Particle.function("cloud_color",setColorFromCloud);
    
    setLEDColor(128,0,255); // initialize the LED 
}

void loop() {
}
