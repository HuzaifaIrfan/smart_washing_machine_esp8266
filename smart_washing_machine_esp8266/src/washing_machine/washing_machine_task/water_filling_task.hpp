
#ifndef _WaterFillingTask_H_
#define _WaterFillingTask_H_

#include "washing_machine_task.hpp"

class WaterFillingTask : public WashingMachineTask
{

private:
  void running_loop();
  void paused_loop();

  int MAXIMUM_COUNTDOWN = 60;
  int DEFAULT_COUNTDOWN = 60;
  int MINIMUM_COUNTDOWN = 30;

public:
  using WashingMachineTask::WashingMachineTask;
  void setup();
  void setup(int tmp_count_down);
};

#endif