#ifndef RESTAPIServer_H
#define RESTAPIServer_H

 
#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include <ArduinoJson.h>

#include "washing_machine/washing_machine_routine.hpp"
#include "washing_machine/washing_machine_controller.hpp"

class RESTAPIServer
{
private:
    void restServerRouting();
    
public:
    RESTAPIServer();
    void setup();
    void loop();
};

extern RESTAPIServer rest_api_server;

#endif