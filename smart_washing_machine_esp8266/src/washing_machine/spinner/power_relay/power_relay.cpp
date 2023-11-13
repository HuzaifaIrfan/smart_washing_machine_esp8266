
#include "power_relay.hpp"

PowerRelay::PowerRelay(short pin) : pin(pin)
{
}

void PowerRelay::setup()
{
    pinMode(pin, OUTPUT);
    off();
}

void PowerRelay::loop()
{
}

void PowerRelay::on()
{
    digitalWrite(pin, HIGH);
    state=true;
}

void PowerRelay::off()
{
    digitalWrite(pin, LOW);
    state=false;
}

bool PowerRelay::return_state()
{
    return state;
}