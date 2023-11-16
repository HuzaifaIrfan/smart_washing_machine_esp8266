
#include "relay.hpp"

Relay::Relay(short pin) : pin(pin)
{
}

void Relay::setup()
{
    pinMode(pin, OUTPUT);
    off();
}

void Relay::loop()
{
}

void Relay::on()
{
    digitalWrite(pin, HIGH);
    state = true;
}

void Relay::off()
{
    digitalWrite(pin, LOW);
    state = false;
}

bool Relay::return_state()
{
    return state;
}