#ifndef RELAY_H
#define RELAY_H

#include <Arduino.h>

class Relay {
  private:
    short pin;
    bool state=false;
  public:
    Relay(short pin);
    void setup();
    void loop();
    void on();
    void off();
    bool return_state();
};

#endif