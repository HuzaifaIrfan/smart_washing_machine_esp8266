#ifndef WASHINGMACHINECONTROLLER_H
#define WASHINGMACHINECONTROLLER_H

#include <Arduino.h>

#include "output/LABELS.hpp"

#include "output/display/display.hpp"

#include "washing_machine/washing_machine.hpp"

#include "washing_machine_state/washing_machine_state.hpp"

#include "washing_machine_state/machine_waiting_state.hpp"
#include "washing_machine_state/water_filling_state.hpp"
#include "washing_machine_state/washer_spinning_state.hpp"
#include "washing_machine_state/clothes_soaking_state.hpp"
#include "washing_machine_state/water_draining_state.hpp"
#include "washing_machine_state/dryer_state.hpp"
#include "washing_machine_state/routine_end_state.hpp"

#include "washing_machine_routine.hpp"

#include "output/LABELS.hpp"

class WashingMachineController
{

private:
  MachineWaitingState machine_waiting_state = MachineWaitingState(&washing_machine);
  WaterFillingState water_filling_state = WaterFillingState(&washing_machine);
  WasherSpinningState washer_spinning_state = WasherSpinningState(&washing_machine);
  ClothesSoakingState clothes_soaking_state = ClothesSoakingState(&washing_machine);
  WaterDrainingState water_draining_state = WaterDrainingState(&washing_machine);
  DryerState dryer_state = DryerState(&washing_machine);
  RoutineEndState routine_end_state = RoutineEndState(&washing_machine);

  WashingMachineState *washing_machine_states[7] = {
      &machine_waiting_state,
      &water_filling_state,
      &washer_spinning_state,
      &clothes_soaking_state,
      &water_draining_state,
      &dryer_state,
      &routine_end_state};

  short current_state_index = MACHINE_WAITING_STATE;

  // short machine_routine_size = sizeof(machine_routine) / sizeof(machine_routine[0]);

  short current_routine_state_pointer = 0;

  void next_routine_state();


public:
  WashingMachineController();
  void setup();
  void loop();

  void reset();
  void increase_current_state_index();
  void decrease_current_state_index();
  void manual_setup_next_state(int machine_routine[4]);
  
  void setup_next_state(int state_index);
  void setup_next_state(int machine_routine[4]);
  
  void run();
  void pause();
  bool is_paused();
  void hold();
  bool is_hold();
  void skip();
  bool is_lid_closed();
  

  int get_current_routine_state_pointer();
  int get_current_state_index();
  int get_count_down();
};

extern WashingMachineController washing_machine_controller;

#endif