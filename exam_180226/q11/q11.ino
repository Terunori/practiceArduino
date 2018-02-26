
int ledPin = 10;
int ledPin2 = 3;
int val = 0;
int count = 0;
int flag = 0;

void setup()
{
    pinMode(ledPin, INPUT);
    pinMode(ledPin2, OUTPUT);
}

void loop()
{
    val = digitalRead(ledPin);

    if (val == HIGH){
        count += 1;
        flag = count % 2;
        delay(400);
    }

    if (flag  == 1){
        digitalWrite(ledPin2, HIGH);
    } else {
        digitalWrite(ledPin2, LOW);
    }
}