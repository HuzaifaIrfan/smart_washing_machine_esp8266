#ifndef _OTA_H_
#define _OTA_H_

// #include "Arduino.h"
// #include <ESP8266WiFi.h>
// #include <ESP8266mDNS.h>
// #include <WiFiUdp.h>
// #include "rest_api_server/rest_api_server.hpp"
// #include <ArduinoOTA.h>

// #include "watch_dog.hpp"

class OTA
{
private:
public:
    OTA();
    void setup();
    void loop();
};

extern OTA ota;

#endif