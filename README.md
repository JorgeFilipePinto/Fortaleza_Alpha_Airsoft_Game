# Fortaleza_Alpha

## Hardware
### Esp32-C3
[Aliexpress](https://pt.aliexpress.com/item/1005005967641936.html#nav-specification)

platformio.ini
```
[env:esp32-c3-devkitm-1]
platform = espressif32
board = esp32-c3-devkitm-1
framework = arduino

monitor_speed = 115200
upload_speed = 57600

upload_protocol = esptool

build_flags =
    -DARDUINO_USB_MODE=1
    -DARDUINO_USB_CDC_ON_BOOT=1
```


![ESP32-C3 description](/assets/image.png)

### DS3231
[Aliexpress](https://pt.aliexpress.com/item/1005008570017428.html?src=google&pdp_npi=4%40dis!EUR!4.47!1.87!!!!!%40!12000045759354307!ppc!!!&snps=y&snpsid=1&src=google&albch=shopping&acnt=752-015-9270&isdl=y&slnk=&plac=&mtctp=&albbt=Google_7_shopping&aff_platform=google&aff_short_key=_oDeeeiG&gclsrc=aw.ds&&albagn=888888&&ds_e_adid=766943355992&ds_e_matchtype=search&ds_e_device=c&ds_e_network=g&ds_e_product_group_id=2489814656527&ds_e_product_id=pt1005008570017428&ds_e_product_merchant_id=5551326180&ds_e_product_country=PT&ds_e_product_language=pt&ds_e_product_channel=online&ds_e_product_store_id=&ds_url_v=2&albcp=22848996932&albag=180511188662&isSmbAutoCall=false&needSmbHouyi=false&gad_source=1&gad_campaignid=22848996932&gclid=Cj0KCQjw2IDFBhDCARIsABDKOJ7ZLQTJJd6Od7INQkLmZBAKbZa3Ee00HN_EXv18vZGSkY3NzqlZINAaAjWZEALw_wcB)

[Library - Adafruit GitHub](https://github.com/adafruit/RTClib/tree/master)

![alt text](/assets/DS3231.png)
![alt text](/assets/DS3231_2.png)

Parâmetros do produto:
- Tensão de trabalho: 3,3-5.5V
- Chip de relógio: chip de relógio de alta precisão DS3231
- Precisão do relógio: dentro da faixa de temperatura ambiente de 0-40℃, com precisão de 2ppm e erro anual de cerca de 1 minuto
- Vem com 2 alarmes de calendário
- Saída de onda quadrada programável
- O relógio em tempo real gera cronometragem de segundos, minutos, horas, semanas, datas, meses e anos e fornece compensação de ano bissexto válida até 2100
- O chip vem com um sensor de temperatura integrado com precisão de ± 3℃
- Chip de armazenamento: AT24C32 (capacidade de armazenamento 32K)
- Interface de barramento IIC, com velocidade máxima de transmissão de 400KHZ (ao operar em 5V)
- Outros dispositivos IIC podem ser conectados em cascata e o endereço 24C32 pode ser modificado por curto-circuito A0/A1/A2. O endereço padrão é 0X57

Example:
```cpp
#include "RTClib.h"

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {
  Serial.begin(115200);

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop () {
    DateTime now = rtc.now();

    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    Serial.print(" since midnight 1/1/1970 = ");
    Serial.print(now.unixtime());
    Serial.print("s = ");
    Serial.print(now.unixtime() / 86400L);
    Serial.println("d");

    DateTime future (now + TimeSpan(7,12,30,6));

    Serial.print(" now + 7d + 12h + 30m + 6s: ");
    Serial.print(future.year(), DEC);
    Serial.print('/');
    Serial.print(future.month(), DEC);
    Serial.print('/');
    Serial.print(future.day(), DEC);
    Serial.print(' ');
    Serial.print(future.hour(), DEC);
    Serial.print(':');
    Serial.print(future.minute(), DEC);
    Serial.print(':');
    Serial.print(future.second(), DEC);
    Serial.println();

    Serial.print("Temperature: ");
    Serial.print(rtc.getTemperature());
    Serial.println(" C");

    Serial.println();
    delay(3000);
}
```

### Leds WS2812b

[Library - Adafruit GitHub](https://github.com/adafruit/Adafruit_NeoPixel)

Example:
```cpp
#include <Adafruit_NeoPixel.h>

#define PIN 1
#define NUMPIXELS 19

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'

  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(0, 150, 0));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(10); // Pause before next pass through loop
  }
}
```

