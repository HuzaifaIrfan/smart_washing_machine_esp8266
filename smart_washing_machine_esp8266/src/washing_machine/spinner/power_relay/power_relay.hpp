#ifndef POWERRELAY_H
#define POWERRELAY_H

#include <Arduino.h>

class PowerRelay {
  private:
    short pin;
    bool state=false;
  public:
    PowerRelay(short pin);
    void setup();
    void loop();
    void on();
    void off();
    bool return_state();
};


#endif