#ifndef KEYPAD_H
#define KEYPAD_H

#include <Arduino.h>

#include "output/display/display.hpp"
#include "washing_machine/washing_machine_controller.hpp"

#include "washing_machine/washing_machine_task/washing_machine_task.hpp"

#include "GPIO_CONFIG.hpp"

class Keypad {
  private:
    Display *display = nullptr;
    WashingMachineController *washing_machine_controller = nullptr;
  public:
    Keypad(Display *display, WashingMachineController *washing_machine_controller);
    void setup();
    void loop();
};

extern Keypad keypad;
#endif