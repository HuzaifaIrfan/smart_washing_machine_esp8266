#ifndef LID_H
#define LID_H

#include <Arduino.h>

#include "GPIO_CONFIG.hpp"

class Lid
{
private:
  short pin;
  static volatile bool lid_open_or_vibration_interrupted;

public:
  Lid(short pin);
  void setup();
  void loop();
  static void lid_open_or_dryer_vibration_switch_interrupt_service_routine();
  
  void close();
  bool is_closed();
};

extern Lid lid;

#endif