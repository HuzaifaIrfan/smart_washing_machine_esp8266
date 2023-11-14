
#ifndef _ClothesSoakingTask_H_
#define _ClothesSoakingTask_H_

#include "washing_machine_task.hpp"

class ClothesSoakingTask : public WashingMachineTask
{

private:
  void running_loop();
  void paused_loop();

  int MAXIMUM_COUNTDOWN = 1800;
  int DEFAULT_COUNTDOWN = 300;
  int MINIMUM_COUNTDOWN = 60;

public:
  using WashingMachineTask::WashingMachineTask;
  void setup();
  void setup(int tmp_count_down);
};

#endif