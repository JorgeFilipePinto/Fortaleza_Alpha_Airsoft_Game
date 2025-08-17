#include <Buzzer.h>

Buzzer::Buzzer(int buzzerPin) {
    this->buzzerPin = buzzerPin;
};


void Buzzer::Begin() {
    pinMode(this->buzzerPin, OUTPUT);
    this->testing();
    
    #ifdef DEBUG
        Serial.println("Buzzer Instantiated");
    #endif
};


void Buzzer::testing() {
    for(int i = 0; i < 3; i++) {
        digitalWrite(this->buzzerPin, HIGH);
        delay(250);
        digitalWrite(this->buzzerPin, LOW);
        delay(250);
    }
};

void Buzzer::Beep(int duration) {

};

