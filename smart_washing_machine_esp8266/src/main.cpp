#include <Arduino.h>

#include "task_scheduler.hpp"

void setup()
{
  task_scheduler.setup();
}

void loop()
{
  task_scheduler.loop();
}
