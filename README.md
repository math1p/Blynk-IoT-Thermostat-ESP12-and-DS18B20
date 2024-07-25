# Thermostat with ESP12 and DS18B20    [![Download](https://img.shields.io/badge/Download-brightgreen.svg)](https://github.com/math1p/Temperature-Humidity-ESP-DS18B20/archive/main.zip)

### Project under development

![Thermostat Image - NO IMAGE](image_link.png)

#### In Rio de Janeiro, temperatures can exceed 35°C on some days. As my house gets very hot, I decided to create a project to monitor the temperature at any time, even away from home.

## Prerequisites

- ESP12 or other ESP controller ([ESP01/01S](https://github.com/esp8266/esp8266-wiki/wiki/Hardware_versions)) with GPIO16 connected to RST (it's possible to use other microcontrollers, but code changes may be necessary)
- Temperature Sensor [DS18B20 (Dallas)](https://pdf1.alldatasheet.com/datasheet-pdf/view/227472/DALLAS/DS18B20.html)
- ~3.3V power supply
- Arduino IDE and necessary libraries
- Blynk account

## How to use

1. Connect ESP12 to Dallas-18B20 sensor according to the [diagram](https://github.com/math1p/IoT-Thermostat-ESP01S-and-DS18B20/tree/fc62981acf8826e92cfca377931825ce31c3a37b/Schematics%20-%20ESP01S%20%26%20ESP12F)
2. Choose a power source (3.3V) to power the ESP12 and the sensor
3. Configure the settings and make adjustments according to your preference in: `config.h`
4. Install the necessary libraries and load the firmware into the ESP12
5. The thermostat will start working automatically
6. Log in to [Blynk](https://blynk.cloud) account

## Settings

In the `config.h` file it is possible to adjust some settings such as: Information for connecting to the Blynk server, network credentials for WiFi connection, the pin to which the sensor is connected and the intervals for reading and sending data.

## Libraries
- ESP8266WiFi
- BlynkSimpleEsp8266
- OneWire
- DallasTemperature

## Notes

I chose ESP12 because I couldn't solder the GPIO16 pin to the RST on the ESP01S, without this it is not possible to use the ESP.deepSleep() function

It is important to highlight that it is not possible to view the temperature directly, requiring a previously configured WiFi connection so that the ESP8266-01S can communicate with the Blynk server. For a project with a similar objective that does not require an internet connection, I suggest using a microcontroller like the ATtiny85 and a display (TM1637).

I won't provide information about Blynk configuration, but I can tell you that you should use Datastreams and Virtualpins. For example: Temperature; V0

For information about Blynk, see https://docs.blynk.io/en

## Future updates
- ESP.deepSleep function
- ESPserver to configure the wifi connection

## Suggestions
- Display (TM1637)
- Wi-Fi connection test using a button (green LED for connection established and red LED for disconnected)
- OTA: Firmware Over-The-Air updates

## License

This project is dedicated to the public domain under the [CC0 License](https://creativecommons.org/publicdomain/zero/1.0/).

## Contact

- Email: matheusito.ito@gmail.com
- Reddit: [mathp](https://www.reddit.com/user/CactoDeVidro/)
