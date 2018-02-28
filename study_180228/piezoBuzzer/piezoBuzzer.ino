/* スイッチの押されている間、Cds光センサへの入力（光強度）に対応する音階の音を鳴らす */
#include <TimerOne.h>
// Timer1は9,10pinを
// Timer1は3,11pinをそれぞれ使うので注意

int anaPin = 1;
int inPin = 4;
int outPin = 13;
int aoutPin = 5;
// int aoutPin = 9; // なぜかいけた
int lightVal = 0;
int tf = 0;
int frequencyNoMoto = 0;

//volatile: 2箇所以上で使う変数
volatile int val = 0;
volatile int frequency = 0;

void timerFire()
{
    // 100msごとに呼び出し
    Serial.print("val = ");
    Serial.print(val);
    Serial.print("\t frequency = ");
    Serial.println(frequency);
}

void setup()
{
    pinMode(outPin, OUTPUT);
    pinMode(aoutPin,OUTPUT);
    pinMode(inPin,INPUT);
    Serial.begin(9600);
    Timer1.initialize(100000); // 100msごと更新
    Timer1.attachInterrupt(timerFire);
    Timer1.start();
}

void loop()
{

    lightVal = analogRead(anaPin);
    val = lightVal / 4; // 光度(256段階) <- 1024 / 256 = 4
    // そのままだとval*180でオーバーフロー(2byte, 値の範囲は-32768から32767)する
    frequencyNoMoto = (int)((float)lightVal * 36 / 1024);
    // 白黒鍵盤に量子化(3 octave)
    frequency = 262 * pow(1.0595, frequencyNoMoto);

    tf = digitalRead(inPin);

    if (tf == HIGH)
    {
        tone(aoutPin, frequency , 50); // 50ms(あまり短いとよろしくない)
        if (val <= 100)
        {
            digitalWrite(outPin, HIGH);
        }
    } else {
        noTone(aoutPin);
        digitalWrite(outPin, LOW);
    }
}
