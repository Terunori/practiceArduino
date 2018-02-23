/* bno055: 9D compass */

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

Adafruit_BNO055 bno = Adafruit_BNO055(55);

void setup(){
    Serial.begin(9600);
    if (!bno.begin())
    {
        Serial.print("Error, no BNO055 detected...");
        while(1);
    }
    delay(1000);
    bno.setExtCrystalUse(true);
}

void loop(){
    sensors_event_t event;
    bno.getEvent(&event);

    Serial.print("X: ");
    Serial.print(event.orientation.x, 4);
    Serial.print("Y: ");
    Serial.print(event.orientation.y, 4);
    Serial.print("Z: ");
    Serial.print(event.orientation.z, 4);
    Serial.println("");

    delay(100);
}