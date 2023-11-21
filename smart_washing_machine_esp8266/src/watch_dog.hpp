#ifndef _WatchDog_H_
#define _WatchDog_H_

#include "Arduino.h"
#include <ESP8266WiFi.h>

class WatchDog
{
private:
public:
    WatchDog();
    void disable();
    void setup();
    void reset();
};

extern WatchDog watch_dog;

#endif