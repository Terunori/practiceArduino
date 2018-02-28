
int inPin = 10;
int outPin = 3;
int val = 0;
int count = 0;
int flag = 0;
int duty = 50;

void setup()
{
    pinMode(inPin, INPUT);
}

void loop()
{
    analogWrite(outPin, duty);
    val = digitalRead(inPin);

    if (val == HIGH){
        count += 1;
        flag = count % 4;
        duty = (flag + 1) * 50;
        
        delay(400);
    }
}