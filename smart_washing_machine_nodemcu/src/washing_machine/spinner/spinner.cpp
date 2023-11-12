
#include "spinner.hpp"

Spinner::Spinner(PowerRelay *clockwise_spinner_power_relay, PowerRelay *anticlockwise_spinner_power_relay) : clockwise_spinner_power_relay(clockwise_spinner_power_relay), anticlockwise_spinner_power_relay(anticlockwise_spinner_power_relay)
{
}

void Spinner::setup()
{
    clockwise_spinner_power_relay->setup();
    anticlockwise_spinner_power_relay->setup();
    spin_state = SPINNER_OFF_STATE;
}

void Spinner::loop()
{
}

void Spinner::stop()
{
    clockwise_spinner_power_relay->off();
    anticlockwise_spinner_power_relay->off();
    spin_state = SPINNER_OFF_STATE;
}

void Spinner::spin_clockwise()
{
    clockwise_spinner_power_relay->on();
    anticlockwise_spinner_power_relay->off();
    spin_state = SPINNER_CW_SPIN_STATE;
}

void Spinner::spin_anti_clockwise()
{
    clockwise_spinner_power_relay->off();
    anticlockwise_spinner_power_relay->on();
    spin_state = SPINNER_ACW_SPIN_STATE;
}

void Spinner::spin_dryer()
{
    spin_clockwise();
}

short Spinner::return_spin_state()
{
    return spin_state;
}

bool Spinner::is_off()
{
    if (return_spin_state() == SPINNER_OFF_STATE)
    {
        return true;
    }
    return false;
}

bool Spinner::is_spin_cw()
{
    if (return_spin_state() == SPINNER_CW_SPIN_STATE)
    {
        return true;
    }
    return false;
}

bool Spinner::is_spin_acw()
{
    if (return_spin_state() == SPINNER_ACW_SPIN_STATE)
    {
        return true;
    }
    return false;
}


PowerRelay clockwise_spinner_power_relay(CLOCKWISE_SPINNER_POWER_RELAY_OUTPUT_PIN);
PowerRelay anticlockwise_spinner_power_relay(ANTICLOCKWISE_SPINNER_POWER_RELAY_OUTPUT_PIN);

Spinner spinner(&clockwise_spinner_power_relay, &anticlockwise_spinner_power_relay);
