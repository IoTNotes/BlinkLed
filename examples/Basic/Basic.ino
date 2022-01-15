#include <BlinkLed.h>

#define BAUD_RATE	115200
#define INVERTED	false

// Create a BlinkLed Object 
BlinkLed myLed(LED_BUILTIN, INVERTED);

void setup() {
	Serial.begin(BAUD_RATE);
	while (!Serial);

	Serial.println("BlinkLed Basic example");
	Serial.println("You should see the LED on your board blinking.");
	Serial.println("Enjoy your projects with BlinkLed Library!");
}

void loop() {
	// Blink internal LED 50ms ON, 1450ms OFF
	myLed.blink(50, 1450);
}
