#include <Arduino.h>
#include <RTClib.h>
#include <../ClockRTC/ClockRTC.h>
#include <../Leds/Leds.h>


ClockRTC clockRTC = ClockRTC();
Leds leds = Leds();

void setup () {
    Serial.begin(115200);
    clockRTC.begin();

    pinMode(10, OUTPUT);
    pinMode(0, INPUT_PULLDOWN);
}


void loop () {
    if(digitalRead(0) == HIGH) {
        leds.test();
        if(clockRTC.isPassed(10)) {
            digitalWrite(10, HIGH);
            #ifdef DEBUG
            Serial.println("Time passed");
            #endif
        } else {
            digitalWrite(10, LOW);
            #ifdef DEBUG
            Serial.println("Time not passed yet remaining");
            #endif
        }
    } else {
        clockRTC.setTic();
        leds.clear();
        leds.setColor();
    }

    delay(50);
}

