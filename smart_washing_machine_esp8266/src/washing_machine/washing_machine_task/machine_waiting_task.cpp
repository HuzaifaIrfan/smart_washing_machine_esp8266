

#include "machine_waiting_task.hpp"

void MachineWaitingTask::setup()
{
    setup(DEFAULT_COUNTDOWN);
}

void MachineWaitingTask::setup(int tmp_count_down)
{
    count_down = validate(tmp_count_down, MAXIMUM_COUNTDOWN, MINIMUM_COUNTDOWN);
    Serial.println(WASHING_MACHINE_TASKS_LABEL[MACHINE_WAITING_TASK] + " countdown Set: " + String(count_down));
}

void MachineWaitingTask::running_loop()
{
    washing_machine->stop();
}

void MachineWaitingTask::paused_loop()
{
    running_loop();
}

bool MachineWaitingTask::skip()
{
    hold_task = false;
    return false;
}
