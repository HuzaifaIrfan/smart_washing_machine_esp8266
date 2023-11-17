
#ifndef _WasherSpinningTask_H_
#define _WasherSpinningTask_H_

#include "washing_machine_task.hpp"

class WasherSpinningTask : public WashingMachineTask
{

private:
  void running_loop();
  void paused_loop();

  int MAXIMUM_COUNTDOWN = 600;
  int DEFAULT_COUNTDOWN = 300;
  int MINIMUM_COUNTDOWN = 30;

  short MAXIMUM_SPIN_TIME = 10;
  short DEFAULT_SPIN_TIME = 5;
  short MINIMUM_SPIN_TIME = 5;

  short MAXIMUM_WAIT_TIME = 10;
  short DEFAULT_WAIT_TIME = 2;
  short MINIMUM_WAIT_TIME = 2;

  short spin_time = DEFAULT_SPIN_TIME;
  short wait_time = DEFAULT_WAIT_TIME;

  bool clockwise_spin_now = false;
  short spin_count_down = 0;

  void spin_loop();
  void toggle_spin();

public:
  using WashingMachineTask::WashingMachineTask;
  void setup();
  void setup(int tmp_count_down);
  void setup(int tmp_count_down, int tmp_spin_time, int tmp_wait_time);
};

#endif