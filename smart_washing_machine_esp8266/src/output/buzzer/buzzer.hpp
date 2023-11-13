#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

#include "GPIO_CONFIG.hpp"

class Buzzer
{
private:
    short pin;

    bool buzz = false;
    short beep_count_set = 0;

    bool buz_now = false;
    short beep_count = 0;

public:
    Buzzer(short pin);
    void setup();
    void loop();

    bool set(short beep_count_set_value);
    void test();
    void off();
};

extern Buzzer buzzer;

#endif