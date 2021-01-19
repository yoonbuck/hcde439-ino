const int LED_COUNT = 5;

const int LED_PIN_START = 8;

void setup() {
    for (int i = 0; i < LED_COUNT; i++) {
        pinMode(LED_PIN_START + i, OUTPUT);
    }
}

int pattern;

void loop() {
    pattern <<= 1;
    pattern += random(2);
    for (int i = 0; i < LED_COUNT; i++) {
        digitalWrite(LED_PIN_START + i, pattern & (1 << i));
    }
    delay(100);
}
