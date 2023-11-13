
#ifndef _WaterFillingState_H_
#define _WaterFillingState_H_

#include "washing_machine_state.hpp"

class WaterFillingState : public WashingMachineState
{

private:
  void running_loop();
  void paused_loop();

  int MAXIMUM_COUNTDOWN = 60;
  int DEFAULT_COUNTDOWN = 60;
  int MINIMUM_COUNTDOWN = 30;

public:
  using WashingMachineState::WashingMachineState;
  void setup();
  void setup(int tmp_count_down);
};

#endif