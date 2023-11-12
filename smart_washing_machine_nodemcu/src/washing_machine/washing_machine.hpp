#ifndef WASHINGMACHINE_H
#define WASHINGMACHINE_H

#include <Arduino.h>

#include "GPIO_CONFIG.hpp"

#include "washing_machine/valve/inlet_valves.hpp"
#include "washing_machine/valve/drain_valve.hpp"

#include "washing_machine/spinner/spinner.hpp"
#include "washing_machine/dryer/dryer.hpp"

#include "washing_machine/lid/lid.hpp"
#include "washing_machine/water_level_sensor/water_level_sensor.hpp"

class WashingMachine
{
private:
  InletValves *inlet_valves = nullptr;
  DrainValve *drain_valve = nullptr;
  Spinner *spinner = nullptr;
  Dryer *dryer = nullptr;

  Lid *lid = nullptr;
  WaterLevelSensor *water_level_sensor = nullptr;

public:
  WashingMachine(InletValves *inlet_valves, DrainValve *drain_valve, Spinner *spinner, Dryer *dryer, Lid *lid, WaterLevelSensor *water_level_sensor);
  void setup();
  void loop();
  void stop();

  // Lid Methods
  void close_lid();
  bool is_lid_closed();

  // Inlet Valve Methods
  void open_inlet_valves();
  void open_hot_inlet_valve();
  void open_cold_inlet_valve();
  void close_inlet_valves();

  // Drain Valve Methods
  void open_drain_valve();
  void close_drain_valve();

  // Spinner Methods
  void stop_spinner();
  void spin_spinner_clockwise();
  void spin_spinner_anti_clockwise();

  // Dryer Methods
  bool open_dryer_drain();
  bool spin_dryer();
  void stop_dryer();
  bool close_drain_and_brake_dryer();
};

extern WashingMachine washing_machine;

#endif