

#include "machine_waiting_state.hpp"

void MachineWaitingState::setup()
{
    setup(DEFAULT_COUNTDOWN);
}

void MachineWaitingState::setup(int tmp_count_down)
{
    count_down = validate(tmp_count_down, MAXIMUM_COUNTDOWN, MINIMUM_COUNTDOWN);
    Serial.println(WASHING_MACHINE_STATES_LABEL[MACHINE_WAITING_STATE] + " countdown Set: " + String(count_down));
}

void MachineWaitingState::running_loop()
{
    washing_machine->stop();
}

void MachineWaitingState::paused_loop()
{
    running_loop();
}

bool MachineWaitingState::skip()
{
    hold_state = false;
    return false;
}
