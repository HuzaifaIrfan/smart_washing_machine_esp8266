

#include "water_draining_state.hpp"

void WaterDrainingState::setup()
{
  setup(DEFAULT_COUNTDOWN);
}

void WaterDrainingState::setup(int tmp_count_down)
{
  count_down = validate(tmp_count_down, MAXIMUM_COUNTDOWN, MINIMUM_COUNTDOWN);
  Serial.println(WASHING_MACHINE_STATES_LABEL[WATER_DRAINING_STATE] + " countdown Set: " + String(count_down));
}

void WaterDrainingState::running_loop()
{
  washing_machine->close_inlet_valves();
  washing_machine->stop_spinner();
  washing_machine->open_drain_valve();
}
void WaterDrainingState::paused_loop()
{
  washing_machine->stop();
}
