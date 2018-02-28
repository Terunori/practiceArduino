
int Trig = 8;   // export
int Echo = 9;   // import
int Duration;   // 時間
float Distance; // 距離

int outPin = 3;

void setup()
{
    Serial.begin(9600);
    pinMode(Trig, OUTPUT);
    pinMode(Echo, INPUT);
    pinMode(outPin, OUTPUT);
}

void loop()
{
    // 超音波を発信
    digitalWrite(Trig, LOW);
    delayMicroseconds(1);
    digitalWrite(Trig, HIGH);
    delayMicroseconds(11);
    digitalWrite(Trig, LOW);

    // 超音波が戻ってくるまでの時間を計測
    Duration = pulseIn(Echo, HIGH);

    //距離計算
    if (Duration > 0)
    {
        // ultrasonic speed is 340m/s = 0.034cm/us
        // 厳密には気温によって異なる
        Distance = Duration / 2;
        Distance = Distance * 340 * 100 / 1000000;
        Serial.print(Duration);
        Serial.print(" us, ");
        Serial.print(Distance);
        if (Distance <= 30) {
            digitalWrite(outPin, HIGH);
            Serial.println("cm Closer than 30 cm");
        } else {
            digitalWrite(outPin,LOW);
            Serial.println("cm");
        }
    }
    delay(1000);
}