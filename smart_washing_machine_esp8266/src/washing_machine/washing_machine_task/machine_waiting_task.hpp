
#ifndef _MachineWaitingTask_H_
#define _MachineWaitingTask_H_

#include "washing_machine_task.hpp"

class MachineWaitingTask : public WashingMachineTask
{

private:
  void running_loop();
  void paused_loop();

  int MAXIMUM_COUNTDOWN = 60;
  int DEFAULT_COUNTDOWN = 5;
  int MINIMUM_COUNTDOWN = 1;

public:
  using WashingMachineTask::WashingMachineTask;
  void setup();
  void setup(int tmp_count_down);
  bool skip();
};

#endif