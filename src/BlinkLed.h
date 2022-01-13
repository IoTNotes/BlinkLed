#ifndef _BLINK_LED_H
#define _BLINK_LED_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class BlinkLed {
private:
	enum ledState { OFF, ON };
	uint32_t __lastBlink;
	uint8_t __pin;
	bool __inverted;
	ledState __state;

public:
	BlinkLed(uint8_t pin, bool isInverted = false);
	~BlinkLed() {};

	void blink(uint32_t timeON, uint32_t timeOFF = 0);
	void on();
	void off();
	void toggle();
};


#endif

