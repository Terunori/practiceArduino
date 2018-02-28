#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

int ledPin = 3;
int error = 20;
int orient = 0;

Adafruit_BNO055 bno = Adafruit_BNO055(55);

void setup(){
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
    if (!bno.begin()){
        Serial.print("Error");
        while(1);
    }
    delay(500);
    bno.setExtCrystalUse(true);
}

void loop()
{
    sensors_event_t event;
    bno.getEvent(&event);
    orient =  event.orientation.x;
    Serial.println(orient);
    if (orient <= error || orient >= 360-error)
    {
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        digitalWrite(ledPin,LOW);
    }
    delay(100);
}