#include <Sirene.h>


Sirene::Sirene(int sirenePin) {
    this->sirenePin = sirenePin;
}


void begin() {
    pinMode(this->sirenePin, OUTPUT);
}


void Sirene::testing() {
    for(int i = 0; i < 3; i++) {
        digitalWrite(this->sirenePin, HIGH);
        delay(250);
        digitalWrite(this->sirenePin, LOW);
        delay(250);
    }
}


void Sirene::ring(int duration) {
        digitalWrite(this->sirenePin, HIGH);
        delay(duration);
        digitalWrite(this->sirenePin, LOW);
}