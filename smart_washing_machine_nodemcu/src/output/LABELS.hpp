#pragma once
#ifndef LABELS_H_
#define LABELS_H_

#include <Arduino.h>

enum WASHING_MACHINE_STATES
{
  MACHINE_WAITING_STATE,
  WATER_FILLING_STATE,
  WASHER_SPINNING_STATE,
  CLOTHES_SOAKING_STATE,
  WATER_DRAINING_STATE,
  DRYER_STATE,
  ROUTINE_END_STATE
};

extern char WASHING_MACHINE_STATES_CHAR[];
extern String WASHING_MACHINE_STATES_LABEL[];



#endif