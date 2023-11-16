

#include "sequence_end_task.hpp"

void SequenceEndTask::setup()
{
    setup(DEFAULT_COUNTDOWN, 10);
}

void SequenceEndTask::setup(int tmp_count_down)
{
    setup(tmp_count_down, 10);
}

void SequenceEndTask::setup(int tmp_count_down, int beep_count)
{
    buzzer.set(beep_count);
    count_down = validate(tmp_count_down, MAXIMUM_COUNTDOWN, MINIMUM_COUNTDOWN);
    Serial.println(WASHING_MACHINE_TASKS_LABEL[SEQUENCE_END_TASK] + " countdown Set: " + String(count_down));
    Serial.println("beep_count:" + String(beep_count));
}

void SequenceEndTask::setup(int tmp_count_down, int beep_count, int var_2)
{
    setup(tmp_count_down, beep_count);
}

void SequenceEndTask::running_loop()
{
    washing_machine->open_drain_valve();
    washing_machine->close_inlet_valves();
    washing_machine->stop_spinner();
}

void SequenceEndTask::paused_loop()
{
    running_loop();
}

bool SequenceEndTask::skip()
{
    return false;
}