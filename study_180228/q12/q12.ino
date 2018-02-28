#include <Servo.h>

int ledPin = 10;
int val = 0;
int count = 0;
int flag = 0;

Servo myservo;

void setup()
{
    pinMode(ledPin, INPUT);
    myservo.attach(3);
}

void loop()
{
    val = digitalRead(ledPin);

    if (val == HIGH)
    {
        count += 1;
        flag = count % 2;
        delay(400);
    }

    if (flag == 1)
    {
        myservo.write(90);
    }
    else
    {
        myservo.write(0);
    }
}