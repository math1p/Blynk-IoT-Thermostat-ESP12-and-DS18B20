[![Download](https://img.shields.io/badge/Download-brightgreen.svg)](https://github.com/math1p/Temperature-Humidity-ESP-DS18B20/archive/main.zip)

# Termostato SmartHome com ESP01S e DS18B20
![Imagem do Termostato](link_da_imagem.png)

## Demonstração

[Veja o Termostato em Ação](link_da_demo.gif)

## Pré-requisitos

- ESP01S (é possível usar outros microcontroladores, mas serão necesárias alterações no código)
- Sensor de Temperatura DS18B20 ![(datasheet)](https://pdf1.alldatasheet.com/datasheet-pdf/view/227472/DALLAS/DS18B20.html)
- Arduino IDE e as bibliotecas necessárias

## Como Usar

1. Conecte o ESP01S ao sensor DS18B20
2. Defina as configurações de acordo com a sua preferência em: `config.h`.
3. Instale as bibliotecas necessárias e carregue o firmware no ESP01S.
4. O termostato começará a funcionar automaticamente.

## Configuração

No arquivo `config.h`, você pode ajustar as configurações do Blynk, o pino no qual o sensor está conectado e intervalos de leitura do sensor.

## Bibliotecas
- ESP8266WiFi
- BlynkSimpleEsp8266
- OneWire
- DallasTemperature

## Licença

Este projeto é dedicado ao domínio público sob a [Licença CC0](https://creativecommons.org/publicdomain/zero/1.0/).

## Contato

- Email: matheusito.ito@gmail.com
