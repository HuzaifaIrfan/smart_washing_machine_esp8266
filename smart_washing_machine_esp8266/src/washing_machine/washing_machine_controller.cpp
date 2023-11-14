
#include "washing_machine_controller.hpp"

WashingMachineController::WashingMachineController()
{
}

void WashingMachineController::setup()
{
  washing_machine.setup();
  reset();
}

void WashingMachineController::loop()
{
  if (current_task_task_pointer < 15)
  {
    if (washing_machine_tasks[current_task_index]->loop())
    {
      next_task_task();
    }
  }
  display.display_current_task(washing_machine_task_sequence, current_task_task_pointer);
  display.display_current_task(current_task_index);
}

void WashingMachineController::next_task_task()
{
  if (current_task_task_pointer < 15)
  {
    current_task_task_pointer = current_task_task_pointer + 1;
    setup_next_task(washing_machine_task_sequence[current_task_task_pointer]);
    run();
  }
}



void WashingMachineController::reset()
{
  current_task_task_pointer = 0;
  setup_next_task(washing_machine_task_sequence[current_task_task_pointer]);
}

void WashingMachineController::setup_next_task(int task_index)
{
  pause();
  current_task_index = validate_washing_machine_task(task_index);
  washing_machine_tasks[current_task_index]->setup();

  // Serial.println("Next Task: " + String(WASHING_MACHINE_TASKS_LABEL[current_task_index]));
}

void WashingMachineController::setup_next_task(int washing_machine_task[4])
{
  pause();
  int task_index = washing_machine_task[0];
  current_task_index = validate_washing_machine_task(task_index);
  washing_machine_tasks[current_task_index]->setup(washing_machine_task[1], washing_machine_task[2], washing_machine_task[3]);
}

  void WashingMachineController::manual_setup_next_task(int washing_machine_task[4]){
    current_task_task_pointer = 14;
    setup_next_task(washing_machine_task);
  }

void WashingMachineController::increase_current_task_index()
{
  if (is_paused())
  {
    current_task_task_pointer = 14;
    current_task_index = current_task_index + 1;
    setup_next_task(current_task_index);
  }
}

void WashingMachineController::decrease_current_task_index()
{
  if (is_paused())
  {
    current_task_task_pointer = 14;
    current_task_index = current_task_index - 1;
    setup_next_task(current_task_index);
  }
}

void WashingMachineController::run()
{
  washing_machine_tasks[current_task_index]->run();
}

void WashingMachineController::pause()
{
  washing_machine_tasks[current_task_index]->pause();
}

bool WashingMachineController::is_paused()
{
  return washing_machine_tasks[current_task_index]->is_paused();
}

void WashingMachineController::hold()
{
  washing_machine_tasks[current_task_index]->hold();
}

bool WashingMachineController::is_hold()
{
  return washing_machine_tasks[current_task_index]->is_hold();
}

bool WashingMachineController::is_lid_closed()
{
  return washing_machine.is_lid_closed();
}



void WashingMachineController::skip()
{
  washing_machine_tasks[current_task_index]->skip();
}

int WashingMachineController::get_current_task_task_pointer()
{
  return current_task_task_pointer;
}
int WashingMachineController::get_current_task_index()
{
  return current_task_index;
}
int WashingMachineController::get_count_down()
{
  return washing_machine_tasks[current_task_index]->get_count_down();
}

WashingMachineController washing_machine_controller;
