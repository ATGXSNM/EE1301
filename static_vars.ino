int led = D7;    // The D7 on-board LED
int led2 = D2;
int button = D3; // The input button (we will set it up with the internal pull-down resistor)

void setup() {
    pinMode(led, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(button, INPUT_PULLDOWN);
}

void loop() {
    // initialization code -- prevButton and led_state state variables declared as local static variables
    static int prevButton = LOW;     // state variable to store if button was HIGH or LOW last time we checked 
    static bool led2_state = false;  // state variable to store the current state of led2


    int curButton = digitalRead(button);
    if(curButton == HIGH && prevButton == LOW){
        // a transition happened -- the user has just pressed the button
        // toggle led2
        led2_state = !led2_state;
        digitalWrite(led2, led2_state);
	}
	prevButton = curButton;  // record the state of the button for the next round
	
	digitalWrite(led, LOW);	// Turn OFF the LED
	delay(1000);               // Wait for 1000mS = 1 second
	digitalWrite(led, HIGH);   // Turn ON the LED
	delay(1000);               // Wait for 1000mS = 1 second
}
