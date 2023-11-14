

#include "washing_machine_task_sequence.hpp"

// int DEFAULT_MACHINE_TASK_SEQUENCE[7][4] = {
//     {MACHINE_WAITING_TASK, 1, 0, 0},
//     {WATER_FILLING_TASK, 90, 0, 0},
//     {WASHER_SPINNING_TASK, 350, 5, 2},
//     {CLOTHES_SOAKING_TASK, 350, 0, 0},
//     {WATER_DRAINING_TASK, 200, 0, 0},
//     {DRYER_TASK, 200, 0, 0},
//     {SEQUENCE_END_TASK, 5, 0, 0}};

int washing_machine_task_sequence[16][4] = {
    {MACHINE_WAITING_TASK, 1, 0, 0},
    {WATER_FILLING_TASK, 90, 0, 0},
    {WASHER_SPINNING_TASK, 350, 5, 2},
    {CLOTHES_SOAKING_TASK, 350, 0, 0},
    {WATER_DRAINING_TASK, 200, 0, 0},
    {WATER_FILLING_TASK, 90, 0, 0},
    {WASHER_SPINNING_TASK, 350, 5, 2},
    {WATER_DRAINING_TASK, 200, 0, 0},
    {DRYER_TASK, 200, 0, 0},
    {SEQUENCE_END_TASK, 5, 0, 0},
    {MACHINE_WAITING_TASK, 1, 0, 0},
    {MACHINE_WAITING_TASK, 1, 0, 0},
    {MACHINE_WAITING_TASK, 1, 0, 0},
    {MACHINE_WAITING_TASK, 1, 0, 0},
    {MACHINE_WAITING_TASK, 1, 0, 0},
    {MACHINE_WAITING_TASK, 1, 0, 0}};

int validate_washing_machine_task(int washing_machine_task)
{
    return validate(washing_machine_task, SEQUENCE_END_TASK, MACHINE_WAITING_TASK);
}

void change_washing_machine_task_sequence(int tmp_washing_machine_task_sequence[16][4])
{
    for (int i = 0; i < 16; ++i)
    {
        washing_machine_task_sequence[i][0] = validate_washing_machine_task(tmp_washing_machine_task_sequence[i][0]);
        for (int j = 1; j < 4; ++j)
        {
            washing_machine_task_sequence[i][j] = tmp_washing_machine_task_sequence[i][j];
        }
    }
}

bool get_washing_machine_task_sequence(int tmp_washing_machine_task_sequence[16][4])
{
    for (int i = 0; i < 16; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            tmp_washing_machine_task_sequence[i][j] = washing_machine_task_sequence[i][j];
        }
    }
    return true;
}
