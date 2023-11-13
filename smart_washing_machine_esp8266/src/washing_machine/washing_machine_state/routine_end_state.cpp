

#include "routine_end_state.hpp"

void RoutineEndState::setup()
{
    setup(DEFAULT_COUNTDOWN, 10);
}

void RoutineEndState::setup(int tmp_count_down)
{
    setup(tmp_count_down, 10);
}

void RoutineEndState::setup(int tmp_count_down, int beep_count)
{
    buzzer.set(beep_count);
    count_down = validate(tmp_count_down, MAXIMUM_COUNTDOWN, MINIMUM_COUNTDOWN);
    Serial.println(WASHING_MACHINE_STATES_LABEL[ROUTINE_END_STATE] + " countdown Set: " + String(count_down));
    Serial.println("beep_count:" + String(beep_count));
}

void RoutineEndState::setup(int tmp_count_down, int beep_count, int var_2)
{
    setup(tmp_count_down, beep_count);
}

void RoutineEndState::running_loop()
{
    washing_machine->open_drain_valve();
    washing_machine->close_inlet_valves();
    washing_machine->stop_spinner();
}

void RoutineEndState::paused_loop()
{
    running_loop();
}

bool RoutineEndState::skip()
{
    hold_state = false;
    return false;
}