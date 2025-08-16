#pragma once
#include <Arduino.h>
#include <RTClib.h>

class ClockRTC {
    private:
        DateTime toc;
        DateTime tic;

    public:
        RTC_DS3231 rtc;

        ClockRTC();

        ~ClockRTC() {};

        void begin();

        void adjust(const DateTime& dt);

        DateTime now();

        float getTemperature();

        bool isPassed(int duration);

        void setTic();
};

