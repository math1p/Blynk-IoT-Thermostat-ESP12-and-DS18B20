# Thermostat with ESP01S and DS18B20    [![Download](https://img.shields.io/badge/Download-brightgreen.svg)](https://github.com/math1p/Temperature-Humidity-ESP-DS18B20/archive/main.zip)

### Project under development

![Thermostat Image - NO IMAGE](image_link.png)

## Prerequisites

- ESP8266-01S (it is possible to use other microcontrollers, but code changes may be necessary)
- Temperature Sensor ![DS18B20 (Dallas)](https://pdf1.alldatasheet.com/datasheet-pdf/view/227472/DALLAS/DS18B20.html)
- 3.3V power supply
- Arduino IDE and necessary libraries

## How to use

1. Connect ESP01S to Dallas-18B20 sensor
2. Choose a power source (3.3V) to power the ESP01S and the sensor
3. Configure the settings and make adjustments according to your preference in: `config.h`
4. Install the necessary libraries and load the firmware into the ESP01S
5. The thermostat will start working automatically

## Settings

In the `config.h` file it is possible to adjust some settings such as: Information for connecting to the Blynk server, network credentials for WiFi connection, the pin to which the sensor is connected and the intervals for reading and sending data.

## Libraries
- ESP8266WiFi
- BlynkSimpleEsp8266
- OneWire
-DallasTemperature

## Notes

It is important to highlight that it is not possible to view the temperature directly, requiring a previously configured WiFi connection so that the ESP8266-01S can communicate with the Blynk server. For a project with a similar objective that does not require an internet connection, I suggest using a microcontroller like the ATtiny85 and a display (TM1637).

## Additional features
- ESP.deepSleep function
- Display

## License

This project is dedicated to the public domain under the [CC0 License](https://creativecommons.org/publicdomain/zero/1.0/).

## Contact

- Email: matheusito.ito@gmail.com
