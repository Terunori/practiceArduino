
// LED blink

//set pins
int led = 13;
int led2 = 2;

// setup
void setup()
{
    pinMode(led, OUTPUT);
    pinMode(led2, OUTPUT);
}

// main
void loop()
{
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led2, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(300);
    digitalWrite(led2, LOW);
    delay(400);
}

/*--- end of the program ---*/