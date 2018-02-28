#include <TimerOne.h>

int anaPin = 1;
int outPin = 3;
int lightVal = 0;
volatile int val = 0;

void timerFire() {
    //100msごとに呼び出し
    Serial.println(val);
}

void setup() {
    pinMode(outPin, OUTPUT);
    Serial.begin(9600);
    Timer1.initialize(100); //マイクロ秒単位で設定
    Timer1.attachInterrupt(timerFire);
}

void loop() {
    lightVal = analogRead(anaPin);
    val = lightVal / 4; // 光度(256段階)
    if (val >= 100) {
        digitalWrite(outPin,HIGH);
    } else {
        digitalWrite(outPin,LOW);
    }
}