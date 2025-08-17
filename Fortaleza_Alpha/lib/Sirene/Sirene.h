#pragma once

#include <Arduino.h>


class Sirene {
    private:
        int sirenePin;

    public:
        Sirene(int sirenePin);
        ~Sirene();

        void begin();
        void testing();
        void ring(int duration);
};