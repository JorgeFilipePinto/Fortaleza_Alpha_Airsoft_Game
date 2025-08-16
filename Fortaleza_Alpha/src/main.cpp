#include <Arduino.h>
#include <RTClib.h>
#include <../ClockRTC/ClockRTC.h>


ClockRTC clockRTC = ClockRTC();

void setup () {
    Serial.begin(115200);
    clockRTC.begin();

    pinMode(10, OUTPUT);
    pinMode(0, INPUT_PULLDOWN);
    clockRTC.tic = clockRTC.now();
}


void loop () {
    if(digitalRead(0) == HIGH) {
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
        clockRTC.tic = clockRTC.now();
    }

    delay(50);
}

