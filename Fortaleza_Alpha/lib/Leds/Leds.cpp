#include "Leds.h"

Leds::Leds(int numPixels, uint8_t r, uint8_t g, uint8_t b) {
    this->numPixels = numPixels;
    this->red = r;
    this->green = g;
    this->blue = b;
}

void Leds::begin(Adafruit_NeoPixel* strip) {
    this->strip = strip;
    this->strip->Color(this->red, this->green, this->blue);
    #ifdef DEBUG
        this->strip->setBrightness(50);
    #else
        this->strip->setBrightness(255);
        this->strip->begin();
        this->strip->show();
    #endif
}

void Leds::test() {
    this->strip->setPixelColor(0, this->red, this->green, this->blue);
    this->strip->show();
}


void Leds::clear() {
    this->strip->clear();
    this->strip->show();
}


void Leds::setColor(uint8_t r, uint8_t g, uint8_t b) {
    this->red = r;
    this->green = g;
    this->blue = b;
}
