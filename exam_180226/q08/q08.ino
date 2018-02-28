#include <Servo.h>

int ledPin = 3;
int duty = 0;

Servo myservo;

void setup() {
    myservo.attach(3);
}

void loop()
{
    if (duty == 90){
        duty = 0;
    } else {
        duty = 90;
    }
    myservo.write(duty);
    delay(1000);
}