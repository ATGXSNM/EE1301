int button = D2;                      // button is connected to D2
int LED = D7;                         // LED is connected to D7 (on-board LED)
bool prev_button_state = false;
bool curr_button_state = false;
bool led_state = false;

void setup()
{
  pinMode(LED, OUTPUT);               // sets pin as output
  pinMode(button, INPUT_PULLDOWN);    // sets pin as input
}

void loop()
{
    // toggle the LED if the button is pressed
    curr_button_state = digitalRead(button);
    if(curr_button_state == true && prev_button_state == false) {
        delay(40); // debouncing
        prev_button_state = true;
        led_state = !led_state;
        digitalWrite(LED, led_state);          // set the LED on
    } else if(curr_button_state == false){
        prev_button_state = false;
    }
    //delay(200);
}
