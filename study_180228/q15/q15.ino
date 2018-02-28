
int anaPin = 1;
int lightVal = 0;
int val = 0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    lightVal = analogRead(anaPin);
    val = lightVal / 4; // 光度(256段階)
    Serial.println(val);
    delay(100);
}