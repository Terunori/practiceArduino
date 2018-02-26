
int ledPin = 3;
int analogPin = 1; // use A1
int val = 0;
int threshold = 500;

void setup()
{
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    val = analogRead(analogPin);
    Serial.println(val);
    if (val <= threshold)
    {
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        digitalWrite(ledPin, LOW);
    }
}