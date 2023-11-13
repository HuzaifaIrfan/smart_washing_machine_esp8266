
#include "washing_machine_controller.hpp"

WashingMachineController::WashingMachineController()
{
}

void WashingMachineController::setup()
{
  washing_machine.setup();
  reset();
}

void WashingMachineController::loop()
{
  if (current_routine_state_pointer < 15)
  {
    if (washing_machine_states[current_state_index]->loop())
    {
      next_routine_state();
    }
  }
  display.display_current_routine(machine_routines, current_routine_state_pointer);
  display.display_current_state(current_state_index);
}

void WashingMachineController::next_routine_state()
{
  if (current_routine_state_pointer < 15)
  {
    current_routine_state_pointer = current_routine_state_pointer + 1;
    setup_next_state(machine_routines[current_routine_state_pointer]);
    run();
  }
}



void WashingMachineController::reset()
{
  current_routine_state_pointer = 0;
  setup_next_state(machine_routines[current_routine_state_pointer]);
}

void WashingMachineController::setup_next_state(int state_index)
{
  pause();
  current_state_index = validate_machine_state(state_index);
  washing_machine_states[current_state_index]->setup();

  // Serial.println("Next State: " + String(WASHING_MACHINE_STATES_LABEL[current_state_index]));
}

void WashingMachineController::setup_next_state(int machine_routine[4])
{
  pause();
  int state_index = machine_routine[0];
  current_state_index = validate_machine_state(state_index);
  washing_machine_states[current_state_index]->setup(machine_routine[1], machine_routine[2], machine_routine[3]);
}

  void WashingMachineController::manual_setup_next_state(int machine_routine[4]){
    current_routine_state_pointer = 14;
    setup_next_state(machine_routine);
  }

void WashingMachineController::increase_current_state_index()
{
  if (is_paused())
  {
    current_routine_state_pointer = 14;
    current_state_index = current_state_index + 1;
    setup_next_state(current_state_index);
  }
}

void WashingMachineController::decrease_current_state_index()
{
  if (is_paused())
  {
    current_routine_state_pointer = 14;
    current_state_index = current_state_index - 1;
    setup_next_state(current_state_index);
  }
}

void WashingMachineController::run()
{
  washing_machine_states[current_state_index]->run();
}

void WashingMachineController::pause()
{
  washing_machine_states[current_state_index]->pause();
}

bool WashingMachineController::is_paused()
{
  return washing_machine_states[current_state_index]->is_paused();
}

void WashingMachineController::hold()
{
  washing_machine_states[current_state_index]->hold();
}

bool WashingMachineController::is_hold()
{
  return washing_machine_states[current_state_index]->is_hold();
}

void WashingMachineController::skip()
{
  washing_machine_states[current_state_index]->skip();
}

int WashingMachineController::get_current_routine_state_pointer()
{
  return current_routine_state_pointer;
}
int WashingMachineController::get_current_state_index()
{
  return current_state_index;
}
int WashingMachineController::get_count_down()
{
  return washing_machine_states[current_state_index]->get_count_down();
}

WashingMachineController washing_machine_controller;
