
#ifndef _SequenceEndTask_H_
#define _SequenceEndTask_H_

#include "washing_machine_task.hpp"
#include "output/buzzer/buzzer.hpp"

class SequenceEndTask : public WashingMachineTask
{

private:
  void running_loop();
  void paused_loop();

  int MAXIMUM_COUNTDOWN = 30;
  int DEFAULT_COUNTDOWN = 5;
  int MINIMUM_COUNTDOWN = 5;

public:
  using WashingMachineTask::WashingMachineTask;
  void setup();
  void setup(int tmp_count_down);
  void setup(int tmp_count_down, int beep_count);
  void setup(int tmp_count_down, int beep_count, int var_2);



  bool skip();
};

#endif