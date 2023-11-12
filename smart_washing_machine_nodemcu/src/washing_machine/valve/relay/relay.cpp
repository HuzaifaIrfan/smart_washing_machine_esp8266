
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
    digitalWrite(pin, LOW);
    state = true;
}

void Relay::off()
{
    digitalWrite(pin, HIGH);
    state = false;
}

bool Relay::return_state()
{
    return state;
}