

#include "water_draining_task.hpp"

void WaterDrainingTask::setup()
{
  setup(DEFAULT_COUNTDOWN);
}

void WaterDrainingTask::setup(int tmp_count_down)
{
  count_down = validate(tmp_count_down, MAXIMUM_COUNTDOWN, MINIMUM_COUNTDOWN);
  Serial.println(WASHING_MACHINE_TASKS_LABEL[WATER_DRAINING_TASK] + " countdown Set: " + String(count_down));
}

void WaterDrainingTask::running_loop()
{
  washing_machine->close_inlet_valves();
  washing_machine->stop_spinner();
  washing_machine->open_drain_valve();
}
void WaterDrainingTask::paused_loop()
{
  running_loop();
  // washing_machine->stop();
}
