#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>


class Leds {
    private:
        uint8_t red;
        uint8_t green;
        uint8_t blue;
        int numPixels;
        Adafruit_NeoPixel* strip;

    public:
        Leds(int numPixels = 19, uint8_t r = 255, uint8_t g = 255, uint8_t b = 255);
        ~Leds();

        void begin(Adafruit_NeoPixel* strip);
        void setColor(uint8_t r, uint8_t g, uint8_t b);
        void test();
        void clear();
};