
#ifndef _WaterDrainingState_H_
#define _WaterDrainingState_H_

#include "washing_machine_state.hpp"

class WaterDrainingState : public WashingMachineState
{

private:
  void running_loop();
  void paused_loop();

  int MAXIMUM_COUNTDOWN = 300;
  int DEFAULT_COUNTDOWN = 120;
  int MINIMUM_COUNTDOWN = 120;

public:
  using WashingMachineState::WashingMachineState;
  void setup();
  void setup(int tmp_count_down);
};

#endif