
#include "washing_machine.hpp"

WashingMachine::WashingMachine(InletValves *inlet_valves, DrainValve *drain_valve, Spinner *spinner, Dryer *dryer, Lid *lid, WaterLevelSensor *water_level_sensor) : inlet_valves(inlet_valves), drain_valve(drain_valve), spinner(spinner), dryer(dryer), lid(lid), water_level_sensor(water_level_sensor)
{
}

void WashingMachine::setup()
{
    inlet_valves->setup();
    drain_valve->setup();
    spinner->setup();
    dryer->setup();
    lid->setup();
    water_level_sensor->setup();
}

void WashingMachine::loop()
{
}

void WashingMachine::stop()
{
    inlet_valves->close();
    spinner->stop();
    drain_valve->close();
}

// Lid Methods
void WashingMachine::close_lid()
{
    lid->close();
}

bool WashingMachine::is_lid_closed()
{
    return lid->is_closed();
}

// Inlet Valve Methods

void WashingMachine::open_inlet_valves()
{
    inlet_valves->open();
}

void WashingMachine::open_hot_inlet_valve()
{
    inlet_valves->open_hot();
}
void WashingMachine::open_cold_inlet_valve()
{
    inlet_valves->open_cold();
}

void WashingMachine::close_inlet_valves()
{
    inlet_valves->close();
}

// Drain Valve Methods

void WashingMachine::open_drain_valve()
{
    drain_valve->open();
}

void WashingMachine::close_drain_valve()
{
    drain_valve->close();
}

// Spinner Methods

void WashingMachine::stop_spinner()
{
    spinner->stop();
}

void WashingMachine::spin_spinner_clockwise()
{
    spinner->spin_clockwise();
}

void WashingMachine::spin_spinner_anti_clockwise()
{
    spinner->spin_anti_clockwise();
}

// Dryer Methods
bool WashingMachine::open_dryer_drain()
{
    return dryer->open_drain();
}

bool WashingMachine::spin_dryer()
{
    return dryer->spin();
}

void WashingMachine::stop_dryer()
{
    dryer->stop();
}

bool WashingMachine::close_drain_and_brake_dryer()
{
    return dryer->close_drain_and_brake();
}

WashingMachine washing_machine(&inlet_valves, &drain_valve, &spinner, &dryer, &lid, &water_level_sensor);
