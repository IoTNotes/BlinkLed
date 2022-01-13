#include "BlinkLed.h"

BlinkLed::BlinkLed(uint8_t pin, bool isInverted) {
	__pin = pin;
	__inverted = isInverted;

	pinMode(__pin, OUTPUT);
	digitalWrite(__pin, __inverted ? HIGH : LOW);
	__state = OFF;
};

void BlinkLed::blink(uint32_t timeON, uint32_t timeOFF) {
	if (!timeOFF)
		timeOFF = timeON;

	uint32_t timeToWait = (__state == ON) ? timeON : timeOFF;
	uint32_t now = millis();
	if (now - __lastBlink > timeToWait) {
		__lastBlink = now;
		toggle();
	}
};

void BlinkLed::on() {
	digitalWrite(__pin, __inverted ? LOW : HIGH);
	__state = ON;
}

void BlinkLed::off() {
	digitalWrite(__pin, __inverted ? HIGH : LOW);
	__state = OFF;
}

void BlinkLed::toggle() {
	if (__state == ON)
		off();
	else
		on();
}
