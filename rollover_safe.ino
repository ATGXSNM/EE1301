int led1 = D7;    // The D7 on-board LED
int led2 = D6;
int button = D3; // The input button (we will set it up with the internal pull-down resistor)

// initialization code -- prevButton and led_state state variables declared as a global variables
int prevButton = LOW;     // state variable to store if button was HIGH or LOW last time we checked 
bool led1_state = false;   // state variable to store the current state of led1
bool led2_state = false;  // state variable to store the current state of led2

void setup() {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(button, INPUT_PULLDOWN);
}

void loop() {
    // variable to store the next time to toggle the LED, initialize as 1s from now
    static unsigned long int lastToggleTime = 0;  

    unsigned long int currentTime = millis();
    
    int curButton = digitalRead(button);
    if(curButton == HIGH && prevButton == LOW){
        // a transition happened -- the user has just pressed the button
        // toggle led2
        led2_state = !led2_state;
        digitalWrite(led2, led2_state);
	}
	prevButton = curButton;  // record the state of the button for the next round
	
	if(currentTime - lastToggleTime > 1000){
	    led1_state = !led1_state;
	        digitalWrite(led1, led1_state);
		    
		        // calculate the next time to toggle led
			    lastToggleTime = currentTime;
			    }
}
