
#ifndef _ClothesSoakingState_H_
#define _ClothesSoakingState_H_

#include "washing_machine_state.hpp"

class ClothesSoakingState : public WashingMachineState
{

private:
  void running_loop();
  void paused_loop();

  int MAXIMUM_COUNTDOWN = 1800;
  int DEFAULT_COUNTDOWN = 300;
  int MINIMUM_COUNTDOWN = 60;

public:
  using WashingMachineState::WashingMachineState;
  void setup();
  void setup(int tmp_count_down);
};

#endif