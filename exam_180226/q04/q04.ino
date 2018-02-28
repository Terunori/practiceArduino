
int ledPin = 10;
int ledPin2 = 3;
int val = 0;

void setup()
{
    pinMode(ledPin, INPUT);
    pinMode(ledPin2, OUTPUT);
}

void loop()
{
    val = digitalRead(ledPin);
    if (val == HIGH){
        digitalWrite(ledPin2, HIGH);
    } else {
        digitalWrite(ledPin2, LOW);
    }
}