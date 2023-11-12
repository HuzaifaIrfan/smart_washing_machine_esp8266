
#ifndef WASHINGMACHINEROUTINE_H
#define WASHINGMACHINEROUTINE_H

#include "output/LABELS.hpp"

bool get_machine_routines(int tmp_machine_routines[16][4]);
void replace_machine_routines(int tmp_machine_routines[16][4]);

extern int machine_routines[][4];

#endif