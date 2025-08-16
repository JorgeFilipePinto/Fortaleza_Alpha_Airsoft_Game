#pragma once
#include <Arduino.h>
#include <RTClib.h>

class ClockRTC {
    private:


    public:
        RTC_DS3231 rtc;
        
        DateTime toc;
        DateTime tic;

        ClockRTC();

        ~ClockRTC() {};

        void begin();

        void adjust(const DateTime& dt);

        DateTime now();

        float getTemperature();

        bool isPassed(int duration);
};

