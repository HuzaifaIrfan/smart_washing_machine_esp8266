#pragma once
#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <Arduino.h>
#include <LiquidCrystal.h>

#include "GPIO_CONFIG.hpp"

class Display
{
public:
  Display();
  void setup();
  void loop();
  void init();
  void set_cursor(uint8_t col, uint8_t row);
  void print(String message);
  void set_cursor_and_print(String message, uint8_t col, uint8_t row);

  void display_current_task_sequence(int washing_machine_task_sequence[][4], short current_task_sequence_pointer);
  void display_current_task(int current_task_index);
  void display_count_down(int count_down);
};

extern Display display;

#endif