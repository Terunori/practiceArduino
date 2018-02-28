
int ledPin = 3;
int duty = 0;

void setup(){}

void loop()
{
    if (duty==200){duty = 0;}
    duty += 50;
    analogWrite(ledPin,duty);
    delay(1000);
}