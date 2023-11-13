
#ifndef _MachineWaitingState_H_
#define _MachineWaitingState_H_

#include "washing_machine_state.hpp"

class MachineWaitingState : public WashingMachineState
{

private:
  void running_loop();
  void paused_loop();

  int MAXIMUM_COUNTDOWN = 60;
  int DEFAULT_COUNTDOWN = 5;
  int MINIMUM_COUNTDOWN = 1;

public:
  using WashingMachineState::WashingMachineState;
  void setup();
  void setup(int tmp_count_down);
  bool skip();
};

#endif