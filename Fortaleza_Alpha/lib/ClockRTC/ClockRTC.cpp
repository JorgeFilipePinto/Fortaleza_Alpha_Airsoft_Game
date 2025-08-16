#include "ClockRTC.h"

#include "ClockRTC.h"

ClockRTC::ClockRTC() {
    #ifdef DEBUG
        Serial.println("ClockRTC instance created");
    #endif
}

void ClockRTC::begin() {
    if (! this->rtc.begin()) {
        #ifdef DEBUG
            Serial.println("Couldn't find RTC");
        #endif
    Serial.flush();
    while (1) delay(10);
    }

    if (this->rtc.lostPower()) {
        #ifdef DEBUG
            Serial.println("RTC lost power, let's set the time!");
        #endif
        this->rtc.adjust(DateTime(2025, 1, 1, 0, 0, 0));
    }
    Serial.println("RTC initialized successfully");
};


void ClockRTC::adjust(const DateTime& dt) {
    this->rtc.adjust(dt);
    #ifdef DEBUG
        Serial.print("RTC adjusted to: ");
        Serial.println(dt.timestamp());
    #endif
};


DateTime ClockRTC::now() {
    DateTime now = this->rtc.now();
    char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    #ifdef DEBUG
        Serial.print(clockRTC.now().year(), DEC);
        Serial.print('/');
        Serial.print(clockRTC.now().month(), DEC);
        Serial.print('/');
        Serial.print(clockRTC.now().day(), DEC);
        Serial.print(" (");
        Serial.print(daysOfTheWeek[clockRTC.now().dayOfTheWeek()]);
        Serial.print(") ");
        Serial.print(clockRTC.now().hour(), DEC);
        Serial.print(':');
        Serial.print(clockRTC.now().minute(), DEC);
        Serial.print(':');
        Serial.print(clockRTC.now().second(), DEC);
        Serial.println();
    #endif
    return now;
};


float ClockRTC::getTemperature() {
    #ifdef DEBUG
        Serial.print("Current temperature: ");
        Serial.print(this->rtc.getTemperature());
        Serial.println(" °C");
    #endif
    return this->rtc.getTemperature();
};


bool ClockRTC::isPassed(int duration) {
    this->toc = this->rtc.now();
    return (this->toc.unixtime() - this->tic.unixtime()) > duration;
};