/* PWM信号 */

int ledPin = 3;
int duty = 0;

void setup (){}

void loop (){
  if (duty<255){
    analogWrite(ledPin, duty);
    delay(50);
    duty += 1;
  } else {
    duty = 0;
  }
}