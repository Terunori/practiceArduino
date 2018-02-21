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
    delay(1000);
    digitalWrite(led, Low);
    delay(1000);
}

/*--- end of the program ---*/