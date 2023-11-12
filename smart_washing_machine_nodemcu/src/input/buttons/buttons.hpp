#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>
#include "ezButton.h"

#include "GPIO_CONFIG.hpp"

#include "washing_machine/washing_machine_controller.hpp"

class Buttons
{
private:
    ezButton *hold_skip_input_button = nullptr;
    WashingMachineController *washing_machine_controller = nullptr;

public:
    Buttons(ezButton *hold_skip_input_button, WashingMachineController *washing_machine_controller);
    void setup();
    void loop();
    void check();
};

extern Buttons buttons;

#endif