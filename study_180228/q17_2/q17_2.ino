#include <MsTimer2.h>
#include <Servo.h>

int anaPin = 1;
int outPin = 13;
int lightVal = 0;
volatile int val = 0;
volatile int duty = 0;

Servo myservo;

void timerFire()
{
    //100msごとに呼び出し
    Serial.print("val = ");
    Serial.print(val);
    Serial.print(" duty = ");
    Serial.println(duty);
}

void setup()
{
    pinMode(outPin, OUTPUT);
    Serial.begin(9600);
    MsTimer2::set(100, timerFire);
    MsTimer2::start();
    myservo.attach(9);
}

void loop()
{
    lightVal = analogRead(anaPin);
    val = lightVal / 4; // 光度(256段階)
    duty = val * 180 / 256; // ??
    myservo.write(duty);
    if (val >= 100)
    {
        digitalWrite(outPin, HIGH);
    }
    else
    {
        digitalWrite(outPin, LOW);
    }
}