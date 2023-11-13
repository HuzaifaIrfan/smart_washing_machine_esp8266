

#include "dryer_state.hpp"

void DryerState::setup()
{
  setup(DEFAULT_COUNTDOWN);
}

void DryerState::setup(int tmp_count_down)
{
  count_down = validate(tmp_count_down, MAXIMUM_COUNTDOWN, MINIMUM_COUNTDOWN);
  Serial.println(WASHING_MACHINE_STATES_LABEL[DRYER_STATE] + " countdown Set: " + String(count_down));
}

void DryerState::running_loop()
{
  if (not washing_machine->is_lid_closed())
  {
    pause();
  }
  washing_machine->open_drain_valve();
  washing_machine->close_inlet_valves();
  washing_machine->spin_dryer();
}

void DryerState::paused_loop()
{
  washing_machine->open_drain_valve();
  washing_machine->close_inlet_valves();
  washing_machine->stop_dryer();
}

void DryerState::run()
{
  washing_machine->close_lid();
  if (washing_machine->is_lid_closed())
  {
    running_state = true;
    hold_state = false;
  }
  else
  {
    pause();
  }
}