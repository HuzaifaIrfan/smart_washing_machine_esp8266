

#ifndef _WashingMachineTask_H_
#define _WashingMachineTask_H_

#include <Arduino.h>

#include "utils/utils.hpp"

#include "output/LABELS.hpp"
#include "output/display/display.hpp"
#include "washing_machine/washing_machine.hpp"

class WashingMachineTask
{
protected:
  WashingMachine *washing_machine = nullptr;
  bool running_task = false;
  bool hold_task = false;
  int count_down = 0;

  int DEFAULT_COUNTDOWN = 5;
  int MAXIMUM_COUNTDOWN = 5;
  int MINIMUM_COUNTDOWN = 5;

  virtual void running_loop(){};
  virtual void paused_loop(){};

public:
  explicit WashingMachineTask(WashingMachine *washing_machine)
      : washing_machine(washing_machine) {}

  virtual void run()
  {
      washing_machine->close_lid();
    running_task = true;
    hold_task = false;
  }
  void pause()
  {
    running_task = false;
    hold_task = true;
  }


  bool is_running()
  {
    return running_task;
  }

  bool is_paused()
  {
    return not running_task;
  }

  bool is_hold()
  {
    return hold_task;
  }

  int get_count_down()
  {
    return count_down;
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
    if (running_task)
    {
      running_loop();
      if (not hold_task)
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
    hold_task = true;
  }

  void unhold()
  {
    hold_task = false;
  }


  virtual bool skip()
  {
    count_down = 0;
    return true;
  }
};

#endif