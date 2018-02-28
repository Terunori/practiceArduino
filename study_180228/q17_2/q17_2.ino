#include <MsTimer2.h>
#include <Servo.h>

int anaPin = 1;
int outPin = 13;
int lightVal = 0;

//volatile: 2箇所以上で使う変数
volatile int val = 0;
volatile int duty = 0;

Servo myservo;

void timerFire()
{
    //100msごとに呼び出し
    Serial.print("val = ");
    Serial.print(val);
    Serial.print("\tduty = ");
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
    val = lightVal / 4; // 光度(256段階) <- 1024 / 256 = 4
    // そのままだとval*180でオーバーフロー(2byte, 値の範囲は-32768から32767)する
    // valを使えば計算値は高々256*180=46080なので「unsign int duty」で定義（非負整数のみ使用）、以下の式を使うことでも回避可能
    // duty = val * 180 / 256;
    duty = (int)((float)lightVal * 180 / 1024);
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
