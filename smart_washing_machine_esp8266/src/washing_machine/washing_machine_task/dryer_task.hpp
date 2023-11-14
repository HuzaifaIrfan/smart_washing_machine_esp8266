
#ifndef _DryerTask_H_
#define _DryerTask_H_

#include "washing_machine_task.hpp"

class DryerTask : public WashingMachineTask
{

private:
  void running_loop();
  void paused_loop();

  int MAXIMUM_COUNTDOWN = 300;
  int DEFAULT_COUNTDOWN = 120;
  int MINIMUM_COUNTDOWN = 60;

public:
  using WashingMachineTask::WashingMachineTask;
  void setup();
  void setup(int tmp_count_down);
  void run();
};

#endif