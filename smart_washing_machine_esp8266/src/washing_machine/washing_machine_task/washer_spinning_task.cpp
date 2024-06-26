

#include "washer_spinning_task.hpp"

void WasherSpinningTask::setup()
{
  setup(DEFAULT_COUNTDOWN);
}

void WasherSpinningTask::setup(int tmp_count_down)
{

  setup(tmp_count_down, DEFAULT_SPIN_TIME, DEFAULT_WAIT_TIME);
}

void WasherSpinningTask::setup(int tmp_count_down, int tmp_spin_time, int tmp_wait_time)
{
  count_down = validate(tmp_count_down, MAXIMUM_COUNTDOWN, MINIMUM_COUNTDOWN);

  spin_time = validate(tmp_spin_time, MAXIMUM_SPIN_TIME, MINIMUM_SPIN_TIME);
  wait_time = validate(tmp_wait_time, MAXIMUM_WAIT_TIME, MINIMUM_WAIT_TIME);

  toggle_spin();

  Serial.println(WASHING_MACHINE_TASKS_LABEL[WASHER_SPINNING_TASK] + " countdown Set: " + String(count_down));
  Serial.println("spin_time:"+String(spin_time)+" wait_time:"+String(wait_time));
}

void WasherSpinningTask::running_loop()
{
  washing_machine->close_drain_valve();
  washing_machine->close_inlet_valves();
  spin_loop();
}

void WasherSpinningTask::paused_loop()
{
  washing_machine->stop();
}

void WasherSpinningTask::spin_loop()
{
  spin_count_down = spin_count_down - 1;
  if (spin_count_down <= wait_time)
  {
    washing_machine->stop();
  }
  else
  {
    if (clockwise_spin_now)
    {
      washing_machine->spin_spinner_clockwise();
    }
    else
    {
      washing_machine->spin_spinner_anti_clockwise();
    }
  }
  if (spin_count_down <= 0)
  {
    toggle_spin();
  }
}

void WasherSpinningTask::toggle_spin()
{
  clockwise_spin_now = not clockwise_spin_now;
  spin_count_down = spin_time + wait_time;
}
