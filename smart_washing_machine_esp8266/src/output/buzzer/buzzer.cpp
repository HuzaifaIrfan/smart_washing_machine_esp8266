
#include "buzzer.hpp"

Buzzer::Buzzer(short pin) : pin(pin)
{
}

void Buzzer::setup()
{
    pinMode(pin, OUTPUT);
}

void Buzzer::loop()
{
    if (buzz)
    {
        if (buz_now)
        {
            digitalWrite(pin, HIGH);
            beep_count = beep_count + 1;
            if (beep_count >= beep_count_set)
            {
                buzz = false;
            }
        }
        else
        {
            digitalWrite(pin, LOW);
        }
        buz_now = not buz_now;
    }
    else
    {
        digitalWrite(pin, LOW);
    }
}

bool Buzzer::set(short beep_count_set_value)
{
    if (not buzz)
    {
        buzz = true;
        beep_count_set = beep_count_set_value;
        beep_count = 0;
        return true;
    }
    return false;
}

void Buzzer::test()
{
    buzz = true;
}

void Buzzer::off()
{
    buzz = false;
}

Buzzer buzzer(BUZZER_OUTPUT_PIN);