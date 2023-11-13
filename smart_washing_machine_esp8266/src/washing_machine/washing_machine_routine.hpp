
#ifndef WASHINGMACHINEROUTINE_H
#define WASHINGMACHINEROUTINE_H

#include "utils/utils.hpp"
#include "output/LABELS.hpp"

int validate_machine_state(int machine_state);
bool get_machine_routines(int tmp_machine_routines[16][4]);
void change_machine_routines(int tmp_machine_routines[16][4]);

extern int machine_routines[][4];

#endif