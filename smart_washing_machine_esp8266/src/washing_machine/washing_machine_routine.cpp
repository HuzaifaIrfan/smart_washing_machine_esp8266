

#include "washing_machine_routine.hpp"

// int DEFAULT_MACHINE_ROUTINE[7][4] = {
//     {MACHINE_WAITING_STATE, 1, 0, 0},
//     {WATER_FILLING_STATE, 90, 0, 0},
//     {WASHER_SPINNING_STATE, 350, 5, 2},
//     {CLOTHES_SOAKING_STATE, 350, 0, 0},
//     {WATER_DRAINING_STATE, 200, 0, 0},
//     {DRYER_STATE, 200, 0, 0},
//     {ROUTINE_END_STATE, 5, 0, 0}};

int machine_routines[16][4] = {
    {MACHINE_WAITING_STATE, 1, 0, 0},
    {WATER_FILLING_STATE, 90, 0, 0},
    {WASHER_SPINNING_STATE, 350, 5, 2},
    {CLOTHES_SOAKING_STATE, 350, 0, 0},
    {WATER_DRAINING_STATE, 200, 0, 0},
    {WATER_FILLING_STATE, 90, 0, 0},
    {WASHER_SPINNING_STATE, 350, 5, 2},
    {WATER_DRAINING_STATE, 200, 0, 0},
    {DRYER_STATE, 200, 0, 0},
    {ROUTINE_END_STATE, 5, 0, 0},
    {MACHINE_WAITING_STATE, 1, 0, 0},
    {MACHINE_WAITING_STATE, 1, 0, 0},
    {MACHINE_WAITING_STATE, 1, 0, 0},
    {MACHINE_WAITING_STATE, 1, 0, 0},
    {MACHINE_WAITING_STATE, 1, 0, 0},
    {MACHINE_WAITING_STATE, 1, 0, 0}};

int validate_machine_state(int machine_state)
{
    return validate(machine_state, ROUTINE_END_STATE, MACHINE_WAITING_STATE);
}

void change_machine_routines(int tmp_machine_routines[16][4])
{
    for (int i = 0; i < 16; ++i)
    {
        machine_routines[i][0] = validate_machine_state(tmp_machine_routines[i][0]);
        for (int j = 1; j < 4; ++j)
        {
            machine_routines[i][j] = tmp_machine_routines[i][j];
        }
    }
}

bool get_machine_routines(int tmp_machine_routines[16][4])
{
    for (int i = 0; i < 16; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            tmp_machine_routines[i][j] = machine_routines[i][j];
        }
    }
    return true;
}
