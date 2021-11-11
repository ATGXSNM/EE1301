int button = D2;                      // button is connected to D2
bool prev_button_state = false;
bool curr_button_state = false;

void setup()
{
  pinMode(button, INPUT_PULLDOWN);    // sets pin as input
}

void loop()
{
    // toggle the LED if the button is pressed
    curr_button_state = digitalRead(button);
    if(curr_button_state == true && prev_button_state == false) {
        delay(40); // debouncing
        prev_button_state = true;
        // publish an event notifying subscribers that button was pressed
        Particle.publish("buttonPress_event");
    } else if(curr_button_state == false){
        prev_button_state = false;
    }
    delay(1000); // only publish events at a max rate of 1/second
}
