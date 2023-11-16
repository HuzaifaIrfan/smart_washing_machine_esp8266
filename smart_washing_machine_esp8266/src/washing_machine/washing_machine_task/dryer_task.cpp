

#include "dryer_task.hpp"

void DryerTask::setup()
{
  setup(DEFAULT_COUNTDOWN);
}

void DryerTask::setup(int tmp_count_down)
{
  count_down = validate(tmp_count_down, MAXIMUM_COUNTDOWN, MINIMUM_COUNTDOWN);
  Serial.println(WASHING_MACHINE_TASKS_LABEL[DRYER_TASK] + " countdown Set: " + String(count_down));
}

void DryerTask::running_loop()
{
  if (not washing_machine->is_lid_closed())
  {
    pause();
    paused_loop();
    return;
  }
  washing_machine->open_drain_valve();
  washing_machine->close_inlet_valves();
  washing_machine->spin_dryer();
}

void DryerTask::paused_loop()
{
  washing_machine->open_drain_valve();
  washing_machine->close_inlet_valves();
  washing_machine->stop_dryer();
}

void DryerTask::run()
{
  washing_machine->close_lid();
  if (washing_machine->is_lid_closed())
  {
    running_task = true;
    hold_task = false;
  }
  else
  {
    pause();
  }
}