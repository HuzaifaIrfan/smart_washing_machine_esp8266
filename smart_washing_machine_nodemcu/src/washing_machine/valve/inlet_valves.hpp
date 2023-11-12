#ifndef INLET_VALVES_H
#define INLET_VALVES_H

#include <Arduino.h>

#include "GPIO_CONFIG.hpp"

#include "washing_machine/valve/relay/relay.hpp"




class InletValves {
  private:
    Relay *hot_water_inlet_valve_relay = nullptr;
    Relay *cold_water_inlet_valve_relay = nullptr;
  public:
    InletValves(Relay *hot_water_inlet_valve_relay, Relay *cold_water_inlet_valve_relay);
    void setup();
    void loop();
    void open();
    void open_hot();
    void open_cold();
    void close();
};

extern InletValves inlet_valves;

#endif