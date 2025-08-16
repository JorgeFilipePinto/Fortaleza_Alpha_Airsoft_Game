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





