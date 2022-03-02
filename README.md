# BlinkLed Library
BlinkLed library helps you to control normal LEDs with the Arduino IDE.

A BlinkLed object can turn **ON**, switch **OFF**, **TOGGLE** and **BLINK** a LED connected to any output pin in both active HIGH and active LOW configurations.

BlinkLed blinks a led using a poolling approach. For this reason BlinkLed can be safetely used in timer-dependent projects.

### Create a BlinkLed object
To create a BlinkLed object you can use the constructor

```<language>
BlinkLed::BlinkLed (pin, isInverted = false);
```

You don't need to setup the pin, it's all done inside the constructor.
##### Examples:
```<language>
// Create a BlinkLed object on pin 2, active HIGH
BlinkLed myLed(2);

// As above, false is the default parameter
BlinkLed myLed(2, false);

// Create a BlynkLed object on pin 2, active LOW
BlinkLed myLed(2, true)
```

### Turn ON, switch OFF or TOGGLE a LED
To perform ON, OFF or TOGGLE operations on a BlinkLed object, just call the corresponding method

```<c++>
// Create a BlinkLed object
#define LED_PIN     LED_BUILTIN
BlinkLed myLed(LED_PIN);

// Turn ON led 
myLed.on();

// Switch OFF led
myLed.off();

// TOGGLE led
myLed.toggle();
```

### BLINK a LED
To blink a LED, BlinkLed class uses a polling approach.<br> This means the LED state is updated on every call to his method blink()

```<language>
BlinkLed::blink(uint32_t timeOn, uint32_t timeOff = 0);
```
The blink() method accepts up to two parameters, to specify the ON and OFF times.<br>
If the second parameter is omitted, LED will blink with a 50% duty cycle (ON time = OFF time).

The blink() method must be placed inside a loop. It's up to the programmer to verify the total cycle time is less than the minimum between ON time and OFF time.

```<language>
// Create two BlinkLed objects on pin 2 and 3
BlinkLed myLed1(2);
BlinkLed myLed2(3);

void setup() {
    ...
    ...
}

void loop () {
    // Blink myLed1 600ms ON and 500ms OFF
    myLed1.blink(500);
    // Blink myLed2 50ms ON and 1500ms OFF
    myLed2.blink(50, 1500);
    ...
    ...
}
```



