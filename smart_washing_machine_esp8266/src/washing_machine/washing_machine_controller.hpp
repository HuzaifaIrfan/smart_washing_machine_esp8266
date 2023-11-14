#ifndef WASHINGMACHINECONTROLLER_H
#define WASHINGMACHINECONTROLLER_H

#include <Arduino.h>

#include "output/LABELS.hpp"

#include "output/display/display.hpp"

#include "washing_machine/washing_machine.hpp"

#include "washing_machine_task/washing_machine_task.hpp"

#include "washing_machine_task/machine_waiting_task.hpp"
#include "washing_machine_task/water_filling_task.hpp"
#include "washing_machine_task/washer_spinning_task.hpp"
#include "washing_machine_task/clothes_soaking_task.hpp"
#include "washing_machine_task/water_draining_task.hpp"
#include "washing_machine_task/dryer_task.hpp"
#include "washing_machine_task/sequence_end_task.hpp"

#include "washing_machine/washing_machine_task_sequence.hpp"

#include "output/LABELS.hpp"

class WashingMachineController
{

private:
  MachineWaitingTask machine_waiting_task = MachineWaitingTask(&washing_machine);
  WaterFillingTask water_filling_task = WaterFillingTask(&washing_machine);
  WasherSpinningTask washer_spinning_task = WasherSpinningTask(&washing_machine);
  ClothesSoakingTask clothes_soaking_task = ClothesSoakingTask(&washing_machine);
  WaterDrainingTask water_draining_task = WaterDrainingTask(&washing_machine);
  DryerTask dryer_task = DryerTask(&washing_machine);
  SequenceEndTask sequence_end_task = SequenceEndTask(&washing_machine);

  WashingMachineTask *washing_machine_tasks[7] = {
      &machine_waiting_task,
      &water_filling_task,
      &washer_spinning_task,
      &clothes_soaking_task,
      &water_draining_task,
      &dryer_task,
      &sequence_end_task};

  short current_task_index = MACHINE_WAITING_TASK;

  // short washing_machine_task_size = sizeof(washing_machine_task) / sizeof(washing_machine_task[0]);

  short current_task_sequence_pointer = 0;

  void next_task_sequence();


public:
  WashingMachineController();
  void setup();
  void loop();

  void reset();
  void increase_current_task_index();
  void decrease_current_task_index();
  void manual_setup_next_task(int washing_machine_task[4]);
  
  void setup_next_task(int task_index);
  void setup_next_task(int washing_machine_task[4]);
  
  void run();
  void pause();
  bool is_paused();
  void hold();
  bool is_hold();
  void skip();
  bool is_lid_closed();
  

  int get_current_task_sequence_pointer();
  int get_current_task_index();
  int get_count_down();
};

extern WashingMachineController washing_machine_controller;

#endif