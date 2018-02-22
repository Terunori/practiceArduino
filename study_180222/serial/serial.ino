// serial通信
// アナログセンサの値を読み取る

int ledPin = 13;
int analogPin = 3;
float val = 0;
int threshold = 512;

void setup()
{
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    val = analogRead(analogPin);
    val = val * 10;
    Serial.print("センサの値は　");
    Serial.println(val);
    if (val >= threshold)
    {
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        digitalWrite(ledPin, LOW);
    }
}