
#ifndef WashingMachineTaskSequence_H
#define WashingMachineTaskSequence_H

#include "utils/utils.hpp"
#include "output/LABELS.hpp"

int validate_washing_machine_task(int washing_machine_task);
bool get_washing_machine_task_sequence(int tmp_washing_machine_task_sequence[16][4]);
void change_washing_machine_task_sequence(int tmp_washing_machine_task_sequence[16][4]);

extern int washing_machine_task_sequence[][4];

#endif