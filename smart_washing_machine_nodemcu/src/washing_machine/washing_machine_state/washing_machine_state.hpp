

#ifndef _WashingMachineState_H_
#define _WashingMachineState_H_

#include <Arduino.h>

#include "output/LABELS.hpp"
#include "output/display/display.hpp"
#include "washing_machine/washing_machine.hpp"

class WashingMachineState
{
protected:
  WashingMachine *washing_machine = nullptr;
  bool running_state = false;
  bool hold_state = false;
  int count_down = 0;

  int DEFAULT_COUNTDOWN = 5;
  int MAXIMUM_COUNTDOWN = 5;
  int MINIMUM_COUNTDOWN = 5;

  virtual void running_loop(){};
  virtual void paused_loop(){};

public:
  explicit WashingMachineState(WashingMachine *washing_machine)
      : washing_machine(washing_machine) {}

  virtual void run()
  {
    running_state = true;
    hold_state = false;
  }
  void pause()
  {
    running_state = false;
    hold_state = true;
  }

  bool is_paused()
  {
    return not running_state;
  }

  bool is_hold()
  {
    return hold_state;
  }

  int get_count_down()
  {
    return count_down;
  }

  int validate(short tmp_value, int maximum_value, int minimum_value)
  {
    if (tmp_value > maximum_value)
    {
      return maximum_value;
    }

    if (tmp_value < minimum_value)
    {
      return minimum_value;
    }

    return tmp_value;
  }

  virtual void setup()
  {
  }

  virtual void setup(int tmp_count_down)
  {
    count_down = validate(tmp_count_down, MAXIMUM_COUNTDOWN, MINIMUM_COUNTDOWN);
  }

  virtual void setup(int tmp_count_down, int var_1, int var_2)
  {
    setup(tmp_count_down);
  }

  bool loop()
  {
    if (running_state)
    {
      running_loop();
      if (not hold_state)
      {
        count_down = count_down - 1;
      }
      display.display_count_down(count_down);
      Serial.println(count_down);
    }
    else
    {
      paused_loop();
    }
    return is_done();
  }

  bool is_done()
  {
    if (count_down <= 0)
    {
      pause();
      return true;
    }
    return false;
  }

  void hold()
  {
    hold_state = true;
  }

  virtual bool skip()
  {
    count_down = 0;
    hold_state = false;
    return true;
  }
};

#endif