
int anaPin = 1;
int inPin = 10;
int val = 0;
int lightVal = 0;

void setup()
{
    pinMode(inPin, INPUT);
    Serial.begin(9600);
}

void loop()
{
    val = digitalRead(inPin);

    if (val == HIGH)
    {
        lightVal = analogRead(anaPin);
        Serial.println(lightVal);
        delay(100);
    } 
}