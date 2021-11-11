// EXAMPLE USAGE
int button = D2;                      // button is connected to D2
int LED = D7;                         // LED is connected to D7 (on-board LED)
bool led_state = false;

void setup()
{
  pinMode(LED, OUTPUT);               // sets pin as output
  pinMode(button, INPUT_PULLDOWN);    // sets pin as input
}

void loop()
{
  // toggle the LED if the button is pressed
  if(digitalRead(button) == HIGH) {
      led_state = !led_state;
      if(led_state){
        digitalWrite(LED, HIGH);          // set the LED on
      } else{
        digitalWrite(LED, LOW);           // set the LED off
      }
    delay(200);                       // waits for 200mS
  }
}
