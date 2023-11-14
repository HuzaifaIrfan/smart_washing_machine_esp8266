

#include "water_filling_task.hpp"

void WaterFillingTask::setup()
{
  setup(DEFAULT_COUNTDOWN);
}

void WaterFillingTask::setup(int tmp_count_down)
{
  count_down = validate(tmp_count_down, MAXIMUM_COUNTDOWN, MINIMUM_COUNTDOWN);
  Serial.println(WASHING_MACHINE_TASKS_LABEL[WATER_FILLING_TASK] + " countdown Set: " + String(count_down));
}

void WaterFillingTask::running_loop()
{
  washing_machine->close_drain_valve();
  washing_machine->stop_spinner();
  washing_machine->open_inlet_valves();
}
void WaterFillingTask::paused_loop()
{
  washing_machine->stop();
}
