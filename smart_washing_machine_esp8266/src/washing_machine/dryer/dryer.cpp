
#include "dryer.hpp"

Dryer::Dryer(DrainValve *drain_valve, Spinner *spinner) : drain_valve(drain_valve), spinner(spinner)
{
}

void Dryer::setup()
{
    // drain_valve  and spinner will already be setup by washing machine
}

void Dryer::loop()
{
}

bool Dryer::open_drain()
{
    if (spinner->is_off())
    {
        drain_valve->open();
        return true;
    }
    return false;
}

bool Dryer::spin()
{
    if (drain_valve->is_open())
    {
        spinner->spin_dryer();
        return true;
    }
    return false;
}

void Dryer::stop()
{
    spinner->stop();
}

bool Dryer::close_drain_and_brake()
{
    if (spinner->is_off())
    {
        drain_valve->close();
        return true;
    }
    return false;
}


Dryer dryer(&drain_valve, &spinner);