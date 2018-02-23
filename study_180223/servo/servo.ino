/* servo */

#include <Servo.h>

Servo myservo;

void setup(){
    myservo.attach(3);
}

void loop(){
    myservo.write(0);
    delay(1000);
    myservo.write(90);
    delay(1000);
}
/* end */