
#include "watch_dog.hpp"

#include "task_scheduler.hpp"

#include "TaskManagerIO.h"

#include "output/buzzer/buzzer.hpp"

#include "washing_machine/washing_machine_controller.hpp"

#include "input/buttons/buttons.hpp"
#include "input/keypad/keypad.hpp"

#include "rest_api_server/rest_api_server.hpp"

TaskScheduler::TaskScheduler()
{
}

void TaskScheduler::setup()
{
  Serial.begin(115200);
  buzzer.setup();
  display.setup();
  buttons.setup();

  washing_machine_controller.setup();

  taskManager.scheduleFixedRate(200, []
                                { buzzer.loop(); });

  taskManager.scheduleFixedRate(1000, []
                                { washing_machine_controller.loop();
                                 watch_dog.reset(); });

  taskManager.scheduleFixedRate(100, []
                                { buttons.loop(); });

  taskManager.scheduleFixedRate(1, []
                                { rest_api_server.loop(); });

  display.init();
  watch_dog.setup();
  rest_api_server.setup();
}

void TaskScheduler::loop()
{
  taskManager.runLoop();
}

TaskScheduler task_scheduler;