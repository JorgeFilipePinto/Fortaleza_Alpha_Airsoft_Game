#pragma once

#include <Arduino.h>

class Buzzer {
    private:
        int buzzerPin;

        void testing();

    public:
        Buzzer(int buzzerPin);
        ~Buzzer();

        void Begin();

        void Beep(int duration);
};