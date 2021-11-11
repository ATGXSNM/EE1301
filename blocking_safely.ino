// First, define the pins we are going to use.
int led = D7;    // The D7 on-board LED
int button = D3; // The input button (we will set it up with the internal
                 // pull-down resistor)

// The setup function runs only once, when the device boots up or is reset
void setup() {
  // Setup the D7 pin as an output (on-board LED), and 
  // D3 as a button input with pull-down
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLDOWN); // instead of INPUT, we used INPUT_PULLDOWN, which
           // activates the internal pull-down resistor. When the button is not
           // pressed, the button pin is connected to LOW (GND) through the pull-down
           // resistor. When the button is pressed, the button pin is connected to 
           // HIGH (3.3V).
}

// The loop function is called repeatedly, as often as possible, after your device
// boots up. Firmware interleaves background tasks associated with WiFi + Cloud
// activity with the code in your loop function by performing the tasks after each loop
// function iteration.
// Note: Code that blocks (stalls) for too long (like more than 5 seconds), can make
// bad things happen (like losing cloud connectivity). As a result, the while loop
// below can cause trouble, since it can prevent the loop function from finishing for
// an arbitrarily long time, causing the device to lose its cloud connectivity. 
// 
// Note 2:
// The built-in delay function is safe to use, even for arbitrarily long delays.
// It is implemented (by Particle) in a way that it safely interleaves required
// background activity with loop function execution. 
void loop() {
     while (digitalRead(button) == HIGH){ // As long as the button is pressed down,
                    // wait here and do nothing. This is called a blocking loop, and
                    // is not a good idea, in general.
        Particle.process();  // allows firmware to perform background tasks while blocking
    }
    
    digitalWrite(led, LOW);	// Turn OFF the LED
    delay(1000);               // Wait for 1000mS = 1 second
    digitalWrite(led, HIGH);   // Turn ON the LED
    delay(1000);               // Wait for 1000mS = 1 second
}
