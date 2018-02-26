
int ledPin = 10;
int ledPin2 = 3;

void setup(){
    pinMode(ledPin, OUTPUT);
    pinMode(ledPin2,OUTPUT);
}

void loop()
{
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin, LOW);
    delay(1000);
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, LOW);
    delay(1000);
}