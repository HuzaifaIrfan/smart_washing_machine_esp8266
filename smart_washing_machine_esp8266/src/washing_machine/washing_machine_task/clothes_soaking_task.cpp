

#include "clothes_soaking_task.hpp"




void ClothesSoakingTask::setup()
{
    setup(DEFAULT_COUNTDOWN);
}

void ClothesSoakingTask::setup(int tmp_count_down)
  {
    count_down = validate(tmp_count_down, MAXIMUM_COUNTDOWN, MINIMUM_COUNTDOWN);
    Serial.println(WASHING_MACHINE_TASKS_LABEL[CLOTHES_SOAKING_TASK]+" countdown Set: "+ String(count_down));
  }


void ClothesSoakingTask::running_loop()
{
    washing_machine->stop();
}

void ClothesSoakingTask::paused_loop()
{
    running_loop();
}
