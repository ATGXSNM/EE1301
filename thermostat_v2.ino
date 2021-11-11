// https://api.particle.io
// GET /v1/devices/{DEVICE_ID}/{VARIABLE}
// curl "https://api.particle.io/v1/devices/{DEVICE_ID}/{VARIABLE}?access_token={ACCESS_TOKEN}"

// POST /v1/devices/{DEVICE_ID}/{FUNCTION}
/* # EXAMPLE REQUEST
curl https://api.particle.io/v1/devices/{DEVICE_ID}/{FUNCTION} \
     -d access_token={ACCESS_TOKEN} \
     -d "args=argument1,argument2,..."
 */
#include "adafruit-led-backpack/adafruit-led-backpack.h"
#include "neopixel/neopixel.h"
#include <math.h>

//#define TEMP_SENSOR 0x27

#define FAN_PIN     D5
#define HEAT_PIN    D6
#define COOL_PIN    D7
#define POT_PIN     A4
// PIR motion detector is not currently being used
//#define PIR_PIN     A7
#define TMP_PIN     A0

/* my RGB LED broke :( -- using a neopixel instead
#define RED_PIN     A6
#define GREEN_PIN   A5
#define BLUE_PIN    A4
*/

// Mode button will toggle state between HEAT <--> OFF <--> COOL; note that switching to HEAT or COOL must switch through OFF state
#define MODE_PIN    D3

#define PIXEL_PIN   D4
#define PIXEL_COUNT 1
#define PIXEL_TYPE  WS2811

// Hysteresis is used to prevent unstable on/off switching when the current temp is close to the desired temp
#define HYSTERESIS 0.5

// threshold to determine if potentiometer has changed position
// consider the position changed if the analog input value changes by more than 64
#define POT_CHANGE_THRESHOLD 64

// number of milliseconds in one day, used for synchronizing clock
#define MILLIS_PER_DAY 86400000

// This global variable records the last time (in ms) that the clock was synchronized
unsigned long lastSync = millis();

// Declaring the neopixel strip -- using this as an RGB LED, since my other one is broken
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// Declare LED backpacks for the display
Adafruit_8x8matrix matrix1;
Adafruit_8x8matrix matrix2;
//Adafruit_8x8matrix matrix3;

// symbols to display during thermostat programming
char program_symbol[3] = {'H','m','T'};

double currentTemp = 0.0;   // This will be the current temp read by the temp sensor
int desiredTemp = 0;        // the HVAC system should try to bring the temperature to this temp
int zone_temps[4];          // for now, implementing 4 temperature zones
int zone_times[4];          // corresponding start times for the zones (in minutes)
int currentZone = -1;       // keep track of what zone we are in and set the temp when a new zone is entered

// I used to have these as bools, but Particle.variable no longer accepts boolean values
int isHeatOn = 0;
int isFanOn = 0;
int isCoolOn = 0;
//bool motionDetected = false;

bool programmed = false;    // tells if the thermostat has been programmed to change desiredTemp automatically at different times
bool displayed = false;     // This global variable keeps track of whether the updated temperature has been displayed yet

// This will allow us to use COOL (0), OFF (1), and HEAT (2) when setting the mode
// This enum no longer works with Particle.variable :(
/*
enum thermostat_mode_t {
    COOL,
    OFF,
    HEAT,
};
thermostat_mode_t mode = OFF;
*/
#define COOL 0
#define OFF 1
#define HEAT 2
int mode = OFF;

int pot;    // variable to store potentiometer readings
int lastChangedPot = -80;   // initialize to -80 so that the first POT reading is guaranteed to trigger a new desired temp

// After setting a new temperature, the display will show the desiredTemp for 3 seconds, then revert to the currentTemp
// This variable is used to count 3000 milliseconds after the temperature is set so we know when to change the display
unsigned long int timeOfSet = 0;

// The button pin is configured with a pulldown resistor, so it defaults LOW and pressing the button changes it to HIGH
int button_val = LOW;
int previous_button = LOW;     // This state varaible stores the previous value sampled from the button; used to check when the button was pressed

// When the button gets pressed, see if it stays pressed for 3 seconds to recognize a long press
unsigned long int timeOfButton = 0;

// This function gets a temperature (and humidity) reading from the I2C temp sensor
/*
double getI2CTemp()
{
    Wire.beginTransmission(TEMP_SENSOR);
    Wire.endTransmission();
    delay(40);
    Wire.requestFrom(TEMP_SENSOR, 4);
    uint8_t b = Wire.read();
    Serial.print("I2C Status bits are ");
    Serial.println(b >> 6);

    int humidity = (b << 8) & 0x3f00;
    humidity |= Wire.read();
    float percentHumidity = humidity / 163.83;
    Serial.print("Relative humidity is ");
    Serial.println(percentHumidity);

    int temp = (Wire.read() << 6) & 0x3fc0;
    temp |= Wire.read() >> 2;
    return temp * 0.018128547885 - 40;
    // ADC -> celcius and celcius -> fahrenheit combined into one formula above
    //temp *= 165;
    //currentTemp = temp / 16383.0 - 40.0;
    //currentTemp = currentTemp * 1.8 + 32.0; // convert to fahrenheit
    //INTcurrentTemp = roundf(currentTemp);
}
*/

double getTMP36Temp()
{
    int reading = analogRead(TMP_PIN);
    //double temperatureC = -40 + (reading-124.1)/12.41;
    return reading * 0.1450443191 - 58;  // temperatureF : This formula is tempuratureC * 1.8 + 32
}

// This function extracts the tens and ones digits of a number and sends them to the displays
void displayTemp(int temp)
{
  char ones = temp % 10;
  char tens = temp / 10;

  matrix1.clear();              // clear the display
  matrix1.setCursor(0, 0);      // start the write curor at the top left
  matrix1.write(tens + '0');    // write the ASCII value of the tens digit
  matrix1.writeDisplay();       // update the display

  matrix2.clear();
  matrix2.setCursor(0, 0);
  matrix2.write(ones + '0');
  matrix2.writeDisplay();
}

// This function sets the color of a common anode RGB LED 
// For the analogWrites, 0 means fully on and 255 means means fully off, since the device is common anode
/* mine broke, using a neopixel instead
void setLEDColor(uint8_t red, uint8_t green, uint8_t blue)
{
    analogWrite(RED_PIN, 255-red);
    analogWrite(GREEN_PIN, 255-green);
    analogWrite(BLUE_PIN, 255-blue);
}
*/
void setLEDColor(uint8_t red, uint8_t green, uint8_t blue)
{
    int newColor = strip.Color(red, green, blue);
    strip.setPixelColor(0, newColor);
    strip.show();
}

// This function saves the desiredTemp to flash memory
// If the device resets or is turned off, the thermostat will load the desiredTemp from memory when it starts up again
// @TODO: perhaps implement a function (or expand this one) to save all the programmed temps for the zones -- This would be easy to do if I create a struct with all the temps and use put() and get()
void saveTemp()
{
  uint8_t temp_byte = (uint8_t)desiredTemp;
  // write the temp to address 0
  EEPROM.update(0, temp_byte);
  Serial.printf("Saved temperature to flash: %d\n",temp_byte);
}

// This function loads a saved temperature from flash memory
// @TODO: perhaps implement a function (or expand this one) to load all the programmed temps
void loadTemp()
{
  // read the value from address 0
  desiredTemp = EEPROM.read(0);
  Serial.printf("Loaded temperature from flash: %d\n",desiredTemp);
  displayTemp(desiredTemp);
}

// This function sets the value of desiredTemp, displays it, saves it to flash, and records the time of setting
int setTemp(int t)
{
  //@TODO: currently no checking to see if temp is in acceptable range [50,90]; should it be added?
  //if(temp>=50 && temp<=90){return -1;}
  desiredTemp = t;
  displayTemp(desiredTemp);
  saveTemp();
  timeOfSet = millis();  // we will show the desiredTemp for 3s before reverting the display to the currentTemp
  displayed = false;    // This variable makes it so that we don't keep calling displayTemp over and over after the 3s has elapsed
  return desiredTemp;
}

// Cloud function to set desired temperature from the web
int setTempFromString(String t)
{
    // if t is outside 50-90 range, do nothing
    int temp = t.toInt();
    if(temp < 50 || temp > 90){
        Serial.print("Invalid temperature: ");
        Serial.println(temp);
        return -1;
    }

    Serial.print("Setting desired temperature from web: ");
    Serial.println(t);

    // if temp is set from the web and we were in programmed mode, we should probably break out to manual mode
    programmed = false;
    
    return setTemp(temp);
}

// Cloud function to set mode (COOL,OFF,HEAT) from the web
int setModeFromString(String m)
{
    int newmode = m.toInt();    // I will expect the web to pass the mode as an int (0=COOL,1=OFF,2=HEAT)
    switch(newmode)
    {
        case COOL:     // COOL
            mode = COOL;
            setLEDColor(0,0,255);     // BLUE
            break;
        case OFF:     // OFF
            mode = OFF;
            setLEDColor(0,255,0);     // GREEN
            break;
        case HEAT:     // HEAT
            mode = HEAT;
            setLEDColor(255,0,0);     // RED
            break;
        default:
            Serial.print("Invalid mode: ");
            Serial.println(m);
            return -1;
    }
    return newmode;
}

// This function is used to initialize the LED backpack displays
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

// set timezone observing DST; offset is from GMT/UTC
void set_DST_timezone(int offset)
{
    // spring ahead on 2nd Sunday in March (earliest possible date = 3/8, latest possible = 3/13)
    // fall back on first Sunday in November (earliest possible date = 11/1, latest possible = 11/7)
    int mm = Time.month();
    int dd = Time.day();
    // if the month is between March and November, we're not in DST, except for beginning of March and end of November
    if( (mm >= 3) && (mm <= 11) )
    {
        if( (mm==3 && dd < 10) || (mm==11 && dd > 4) ) // for simplicity, just averaging; I'll only be off by an hour for a few days at most
        {
            Time.zone(offset-1); 
        } else{
            Time.zone(offset);
        }
    } else{
        Time.zone(offset-1); 
    }
}

// the setup function is called once when the device is turned on
void setup()
{
    Wire.begin();       // initialize an I2C serial interface to communicate with the displays (used to use this for temp/humidity sensor, but replaced with TMP36)
    // @TODO: Add pullup resistors on SCL and SDA as described in particle docs for Wire.
    // @TODO: Do we need a protection diode across the input of the relay circuit? Does it have a built in protection?

    // initialize the neopixel
    strip.begin();

    // initialize the displays, including their I2C addresses
    matrix1.begin(0x70);    
    matrix2.begin(0x71);
    //matrix3.begin(0x72);

    setupMatrix(&matrix1);
    setupMatrix(&matrix2);
    //setupMatrix(&matrix3);

    // Declare cloud functions
    Particle.function("set_temp", setTempFromString);
    Particle.function("set_mode", setModeFromString);
    // Declare cloud variables
    Particle.variable("current_temp", currentTemp); // DOUBLE
    Particle.variable("desired_temp", desiredTemp); // INT
    Particle.variable("mode", mode);                // INT
    Particle.variable("is_heat_on", isHeatOn);      // BOOLEAN -- now INT
    Particle.variable("is_fan_on", isFanOn);        // BOOLEAN -- now INT
    Particle.variable("is_cool_on", isCoolOn);      // BOOLEAN -- now INT
    
    Serial.begin(9600); // setup the serial port

    loadTemp(); // load the set temp that was last stored in flash memory

    // initialize the pins
    pinMode(FAN_PIN, OUTPUT);
    pinMode(HEAT_PIN, OUTPUT);
    pinMode(COOL_PIN, OUTPUT);
    pinMode(POT_PIN, INPUT);  // documentation says not to set pinMode for analogRead
    //pinMode(PIR_PIN, INPUT);
    pinMode(MODE_PIN, INPUT_PULLDOWN);
    //pinMode(RED_PIN, OUTPUT);
    //pinMode(GREEN_PIN, OUTPUT);
    //pinMode(BLUE_PIN, OUTPUT);
    pinMode(PIXEL_PIN, OUTPUT); // not sure if this is needed, might be done already in neopixel library
    
    // initially set the LED to green for OFF mode
    setLEDColor(0,255,0);
    
    // synchronize the clock with the cloud servers
    Particle.syncTime();
    // set time zone for CST
    set_DST_timezone(-5);
}

// the loop function is called repeatedly in a loop
void loop()
{
  static unsigned long int timeToSampleTemp = millis();     // sensor readings
  static unsigned long int timeToSampleInputs = millis();   // button and pot samples
  static unsigned long int timeToActuate = millis();                     // actuation of HVAC system

  if(millis() > timeToSampleTemp)
  {
    // sample temp again after 5s
    timeToSampleTemp += 5000;   // @TODO: may want to make this sample less frequently to reduce power

    // request a temperature measurement over I2C bus
    //currentTemp = getI2CTemp();
    // get a temperature sample from the TMP36
    currentTemp = getTMP36Temp();
      
    Serial.print("Temperature is ");
    Serial.println(currentTemp);
    
    // check if the clock needs to be sync'd (happens once per day)
    // @TODO: can put this in the slowest timer block since it isn't urgent
    if(millis() - lastSync > MILLIS_PER_DAY)
    {
        Particle.syncTime();
        set_DST_timezone(-5);
        lastSync = millis();
    }
  } // end of temperature sampling block
  
  // if a newly set desiredTemp has been displayed for more than 3s, revert display to currentTemp
  if((millis() - timeOfSet > 3000) && !displayed){
    displayTemp(currentTemp);
    displayed = true;
  }
  
  if(millis() > timeToSampleInputs)
  {
      timeToSampleInputs += 1000;   // check the button again after 1s
      // if the button timer was activated due to a button press (indicated by timeOfButton>0) and the button is still pressed, check if this is a long press (longer than 3s)
      if( (timeOfButton > 0) && (button_val == HIGH) )
      {
          // if the button has been pressed for over 3s, this is a long press, enter program mode (or revert to manual temp control if we were already in program mode)
          if(millis() - timeOfButton > 3000)
          {
              Serial.println("Long press detected");
              // if we were in program mode, exit program mode, else enter program mode and set the zone temps
              if(!programmed)
              {
                  // programming state machine has been entered
                  matrix1.clear();
                  matrix1.setCursor(0, 0);
                  matrix1.write('P'); // @TODO: create symbols for a clock (hour), a clock (minute), and a thermometer
                  matrix1.writeDisplay();
                  matrix2.clear();
                  matrix2.setCursor(0, 0);
                  matrix2.write('?');   // @TODO: change this to clock
                  matrix2.writeDisplay();
                  // wait for the button to be released
                  while(digitalRead(MODE_PIN) == HIGH){Particle.process();}  // Particle.process() makes this blocking safe
                  delay(40); // debounce
                        
                  // go through the programming state machine
                  // use the pot to select the desired zone(k) start time and temperature, then press button to save and go to zone(k+1)
                  int t;
                  for(int zone = 0; zone < 4; zone++)
                  {
                      for(int jj = 0; jj < 3; jj++) // need to grab 3 pieces of info for each zone (hour, minute, temp)
                      {
                        matrix1.clear();
                        matrix1.setCursor(0, 0);
                        matrix1.write(program_symbol[jj]); // @TODO: create symbols for a clock (hour), a clock (minute), and a thermometer
                        matrix1.writeDisplay();
                        matrix2.clear();
                        matrix2.setCursor(0, 0);
                        matrix2.write(zone + '0');
                        matrix2.writeDisplay();
                        // button presses will continue to the next state in the state machine
                        while(digitalRead(MODE_PIN) == LOW){Particle.process();}
                        delay(400);
                        // take pot readings and display them until the user selects the desired zone temp
                        while(digitalRead(MODE_PIN) == LOW)
                        {
                            switch(jj)
                            {
                                case 0: // hour
                                    //int t = analogRead(POT_PIN) * (23.0/4095.0);
                                    // combining constants to simplify formula
                                    t = round(analogRead(POT_PIN) * 0.00561660561661);
                                    displayTemp(t);
                                    break;
                                case 1: // minute
                                    //int t = analogRead(POT_PIN) * (59.0/4095.0);
                                    // combining constants to simplify formula
                                    t = round(analogRead(POT_PIN) * 0.01440781440781);
                                    displayTemp(t);
                                    break;
                                case 2: // temperature
                                    //int t = analogRead(POT_PIN) * (40.0/4095.0) + 50.0;
                                    // combining constants to simplify formula
                                    t = round(50.0 + analogRead(POT_PIN) * 0.00976800976801);
                                    displayTemp(t);
                                    break;
                            }
                            Particle.process();
                        }
                        // store the selected temp or time (in minutes)
                        switch(jj)
                        {
                            case 0: // hour
                                zone_times[zone] = t*60;
                                break;
                            case 1: // minute
                                zone_times[zone] += t;
                                break;
                            case 2: // temperature
                                zone_temps[zone] = t;
                            break;
                        }
                        delay(400);
                      }
                  }
                  lastChangedPot = analogRead(POT_PIN); // only need this at the very end of state machine (unless it is possible to break out somehow...?)
                  // @TODO: turn on one of the LEDs in the matrix to indicate that the thermostat is in programmed mode -- ALTERNATIVELY, I can add an offset to R, G, B values in setColor function so they appear as diferent shades of RGB when programmed (e.g., orange, green, cyan) -- just mix in some green!
              } else{
                  // indicate that program mode is exited 
                  matrix1.clear();
                  matrix1.setCursor(0, 0);
                  matrix1.write('O');
                  matrix1.writeDisplay();
                  matrix2.clear();
                  matrix2.setCursor(0, 0);
                  matrix2.write('k');
                  matrix2.writeDisplay();
                  // @TODO: clear the LED in the matrix that indicates that the thermostat is in programmed mode
                  // wait for the button to be released
                  while(digitalRead(MODE_PIN) == HIGH){Particle.process();}
                  delay(40);
              
                  // @TODO: this is just temporary to test the clock
                      displayTemp(Time.hour());
                      delay(3000);
                      displayTemp(Time.minute());
                      delay(3000);
                      Serial.printf("Time is %d : %d\n",Time.hour(),Time.minute());
                  // @TODO delete to here to remove testing of zone temp storage
              } 
              
              // toggle the program mode
              programmed = !programmed;
              
              // reset the button state, since this button press has been handled
              timeOfButton = 0;
              button_val = LOW;
              previous_button = LOW;
          }
      }

    // desired temperature control for programmed mode based on time of day -- it might be better to implement this with interrupts so we don't have to keep checking the time every few seconds
    if(programmed)
    {
        // get the current time in minutes
        int currentTime = 60 * Time.hour() + Time.minute();
        // check what zone we are in and set the desired temp accordingly
        for(int zone = 0; zone < 4; zone++)
        {
            if( ( (zone_times[zone] <= zone_times[(zone+1)%4]) && (currentTime >= zone_times[zone]) && (currentTime < zone_times[(zone+1)%4]) ) || (  (zone_times[zone] > zone_times[(zone+1)%4]) && (currentTime >= zone_times[zone]) || (currentTime < zone_times[(zone+1)%4]) ) ) // First check is for day zones and second check is for overrnight zones
            {
                // if we just entered this zone, set the desired temperature
                if(currentZone != zone)
                {
                    // @TODO: this debug printout could be removed later -- I want to confirm that the zone is entered
                    matrix1.clear();
                    matrix1.setCursor(0, 0);
                    matrix1.write('Z');
                    matrix1.writeDisplay();
                    matrix2.clear();
                    matrix2.setCursor(0, 0);
                    matrix2.write('0' + zone);
                    matrix2.writeDisplay();
                    delay(2000);
                    
                    currentZone = zone;
                    setTemp(zone_temps[zone]);
                }
                break; // break out, since we don't need to check the rest of the zones
            }
        }
    }

    // sample the pot 
    pot = analogRead(POT_PIN);
    Serial.print("Potentiometer reading: ");
    Serial.println(pot);
    
    // If user has adjusted the potentiometer
    // @TODO: If you want the display to change immediately when the pot is adjusted, this needs to go outside the timer block -- currently it only changes up to once per second
    if(abs(pot - lastChangedPot) > POT_CHANGE_THRESHOLD)
    {
        // Don't set temp on boot
        if(lastChangedPot >= 0)
        {
            // map 0-4095 pot range to 50-90 temperature range
            int t = round(pot * (40.0/4095.0) + 50.0);
            setTemp(t);
        
            Serial.print("Setting desired temp based on potentiometer to ");
            Serial.println(t);
        }
        lastChangedPot = pot;
    }

/*
    // Sample the motion detector
    Serial.print("PIR reading: ");
    Serial.println(analogRead(PIR_PIN));

    if (3550 < analogRead(PIR_PIN))
    {
        motionDetected = true;
        // lean more toward comfort than energy efficiency
    }
*/

  } // end of input sampling block
  
    // sample the button
    button_val = digitalRead(MODE_PIN);
  
    // if the button was pressed, debounce and start the button timer
    if( (button_val == HIGH) && (previous_button == LOW) )
    {
        delay(40);  // debounce
      
        // start the timer to check for long press
        // timeOfButton is only greater than 0 when the button is being timed
        timeOfButton = millis();
        previous_button = HIGH;
    }
    
    // if the button was released, debounce and figure out what to do based on how long the button was held down
    if( (button_val == LOW) && (previous_button == HIGH) )
    {
        Serial.println("Short press");
        delay(40);  // debounce
        
        // since long presses will be handled above, this MUST be a short press --> change the MODE
        // wait for a potentiometer change to switch the mode or a button press to leave the mode the same
        while( (button_val == LOW) && (abs(pot - lastChangedPot) < POT_CHANGE_THRESHOLD) )
        {
            pot = analogRead(POT_PIN);
            button_val = digitalRead(MODE_PIN);
            Particle.process();
        }
        
        if(button_val == HIGH)
        {
            Serial.println("Mode change canceled");
            // if the button was pressed again, leave the MODE unchanged
            delay(400); // wait for button release and debouncing
            button_val = LOW;
            
        } else if( (pot - lastChangedPot) > 0 ){
            // if the pot was increased, increase mode
            switch(mode)
            {
                case COOL:
                    mode = OFF;
                    break;
                default:    // OFF or HEAT
                    mode = HEAT;
            }
            Serial.println("Level UP");
        } else{
            // only option left at this point is that pot was decreased --> decrease mode
            switch(mode)
            {
                case HEAT:
                    mode = OFF;
                    break;
                default:    // OFF or COOL
                    mode = COOL;
            }
            Serial.println("Level DOWN");
        }

        // set LED color to indicate mode: RED = HEAT, BLUE = COOL, OFF (or other color) = OFF
        switch(mode)
        {
            case HEAT:
                setLEDColor(255,0,0);     // RED
                break;
            case COOL:
                setLEDColor(0,0,255);     // BLUE
                break;
            default:
                setLEDColor(0,255,0);   // GREEN 
        }
        
        // keep track of the last value sampled from the pot to detect when the user changes it
        lastChangedPot = pot;
        
        // reset the button timer
        timeOfButton = 0;
        
        previous_button = LOW;
    } // end of button press block

    if(millis() > timeToActuate)
    {
        timeToActuate += 2500;  // in reality, this delay can increase even more -- OK to delay actuation by a bit
        // In heating mode, turn on heat when temp is less than the desired temp and the heat is off, and keep heat on until temp raises above desired temp by hysteresis amount
        isHeatOn = ( (!isHeatOn && (currentTemp < desiredTemp)) || (isHeatOn && (currentTemp < (desiredTemp + HYSTERESIS))) ) && (mode == HEAT);
        digitalWrite(HEAT_PIN, (isHeatOn)?HIGH:LOW);

        // In cooling mode, turn on AC when temp is greater than the desired temp and the AC is off, and keep AC on until temp falls below desired temp by hysteresis amount
        isCoolOn = ( (!isCoolOn && (currentTemp > desiredTemp)) || (isCoolOn && (currentTemp > (desiredTemp - HYSTERESIS))) ) && (mode == COOL);
        digitalWrite(COOL_PIN, (isCoolOn)?HIGH:LOW);

        // Run the fan whenever the HEAT or AC is on
        isFanOn = isHeatOn || isCoolOn;
        digitalWrite(FAN_PIN, (isFanOn)?HIGH:LOW);
  
        // Test printout -- can be removed
        static long int printTime = millis();
        if(millis() > printTime)
        {
            printTime += 10000;
            Serial.printf("HEAT=%d, AC=%d, FAN=%d\n",isHeatOn,isCoolOn,isFanOn);
        }
    } // end of actuator block
    
} // end of loop function
