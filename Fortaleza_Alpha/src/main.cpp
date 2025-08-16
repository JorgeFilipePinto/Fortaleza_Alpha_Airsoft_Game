#include <Arduino.h>
#include <RTClib.h>
#include <../ClockRTC/ClockRTC.h>
#include <../Leds/Leds.h>

//#define DEBUG


ClockRTC clockRTC = ClockRTC();
Leds leds = Leds();

volatile bool botaoPressionado = false;
volatile bool tempoAtingido = false;

void taskBotao(void *pvParameters) {
    for (;;) {
        botaoPressionado = (digitalRead(0) == HIGH);
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}


void taskContador(void *pvParameters) {
    for (;;) {
        if (botaoPressionado) {
            if (clockRTC.isPassed(10)) {
                tempoAtingido = true;
            } else {
                tempoAtingido = false;
            }
        } else {
            clockRTC.setTic();
            tempoAtingido = false;
        }
        vTaskDelay(50 / portTICK_PERIOD_MS);
    }
}


void taskLeds(void *pvParameters) {
    for (;;) {
        if (botaoPressionado) {
            leds.setColor();
            if (tempoAtingido) {
                leds.setColor(0, 150, 0);
                digitalWrite(10, HIGH);
            } else {
                digitalWrite(10, LOW);
            }
            leds.test();
        } else {
            leds.clear();
        }
        vTaskDelay(20 / portTICK_PERIOD_MS);
    }
}







void setup () {
    Serial.begin(115200);
    clockRTC.begin();

    pinMode(10, OUTPUT);
    pinMode(0, INPUT_PULLDOWN);

     xTaskCreatePinnedToCore(taskBotao, "Botao", 2048, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(taskContador, "Contador", 2048, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(taskLeds, "Leds", 4096, NULL, 1, NULL, 0);
}


void loop () {
    /*if(digitalRead(0) == HIGH) {
        leds.test();
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
        clockRTC.setTic();
        leds.clear();
        leds.setColor();
    }

    delay(50);*/
}

