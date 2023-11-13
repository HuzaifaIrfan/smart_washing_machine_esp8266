

#include "water_filling_state.hpp"

void WaterFillingState::setup()
{
  setup(DEFAULT_COUNTDOWN);
}

void WaterFillingState::setup(int tmp_count_down)
{
  count_down = validate(tmp_count_down, MAXIMUM_COUNTDOWN, MINIMUM_COUNTDOWN);
  Serial.println(WASHING_MACHINE_STATES_LABEL[WATER_FILLING_STATE] + " countdown Set: " + String(count_down));
}

void WaterFillingState::running_loop()
{
  washing_machine->close_drain_valve();
  washing_machine->stop_spinner();
  washing_machine->open_inlet_valves();
}
void WaterFillingState::paused_loop()
{
  washing_machine->stop();
}
