
#ifndef _WaterDrainingTask_H_
#define _WaterDrainingTask_H_

#include "washing_machine_task.hpp"

class WaterDrainingTask : public WashingMachineTask
{

private:
  void running_loop();
  void paused_loop();

  int MAXIMUM_COUNTDOWN = 1200;
  int DEFAULT_COUNTDOWN = 120;
  int MINIMUM_COUNTDOWN = 120;

public:
  using WashingMachineTask::WashingMachineTask;
  void setup();
  void setup(int tmp_count_down);
};

#endif