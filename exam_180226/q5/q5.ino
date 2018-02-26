
int ledPin = 3;
int analogPin = 1; // use A1
int val = 0;
int threshold = 500;

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    val = analogRead(analogPin);
    if (val <= threshold){
        digitalWrite(ledPin,HIGH);
    } else {
        digitalWrite(ledPin, LOW);
    }
}