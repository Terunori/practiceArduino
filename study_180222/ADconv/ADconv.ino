/* A/D変換 */
// アナログセンサの値を読み取る

int ledPin = 13;
int analogPin = 3;
int val = 0;
int threshold = 512;

void setup(){
    pinMode(ledPin, OUTPUT);
}

void loop(){
    val = analogRead(analogPin);
    if (val >= threshold){
        digitalWrite(ledPin, HIGH);
    } else {
        digitalWrite(ledPin, LOW);
    }
}