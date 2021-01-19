// number of leds to show
const int LED_COUNT = 5;

// first pin (of LED_COUNT) to be used for LED sequence
const int LED_PIN_START = 8;

// setup: runs once at start
void setup() {
    // Repeat for each of the LEDs:
    for (int i = 0; i < LED_COUNT; i++) {
        // Declare the pin associated with each LED
        // as an output which can be written to
        pinMode(LED_PIN_START + i, OUTPUT);
    }
}

// the LED_COUNT least significant bits of pattern
// are used to store and update the current pattern
// displayed by the LEDs
int pattern;

// loop: runs repeatedly until you get bored, power
// runs out, or the universe explodes
void loop() {
    // Shift the bits left one place in pattern, 
    // essentially shifting the bit pattern over
    pattern <<= 1;

    // Add either 0 or 1 to pattern, essentially
    // choosing the new LSB of pattern at random
    pattern += random(2);

    // Repeat for each of the LEDs:
    for (int i = 0; i < LED_COUNT; i++) {
        // The ith least significant bit of pattern is written
        // to the ith LED.
        digitalWrite(LED_PIN_START + i, pattern & (1 << i));
    }

    // Block for 100ms
    delay(100);
}
