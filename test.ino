// Lチカ

//set pins
int led = 13;

// setup
void setup() {
    pinMode(led, OUTPUT)
}

// main
void loop() {
    digitalWrite(led, High);
    delay(500);
    digitalWrite(led, Low);
    delay(500);
}

/*--- end of the program ---*/