int LED = D7;                         // LED is connected to D7 (on-board LED)
bool led_state = false;

// This function is called when buttonPress_event is published
void buttonHandler(const char *event, const char *data)
{
    // toggle the LED if the button is pressed
    led_state = !led_state;
    digitalWrite(LED, led_state); 
}

void setup()
{
  pinMode(LED, OUTPUT);               // sets pin as output
  // subscribe to event and call buttonHandler when event is published
  // The last argument makes this subscription only listen to events published by my devices
  Particle.subscribe("buttonPress_event", buttonHandler, MY_DEVICES);
}

void loop()
{
}
