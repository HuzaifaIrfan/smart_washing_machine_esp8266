
#include "watch_dog.hpp"

#include "task_scheduler.hpp"

#include "TaskManagerIO.h"

#include "output/buzzer/buzzer.hpp"

#include "washing_machine/washing_machine_controller.hpp"

#include "input/buttons/buttons.hpp"
#include "input/keypad/keypad.hpp"

#include "rest_api_server/rest_api_server.hpp"

bool secPassed = false;

#include "ESP8266TimerInterrupt.h" //https://github.com/khoih-prog/ESP8266TimerInterrupt
#include "ESP8266_ISR_Timer.hpp"   //https://github.com/khoih-prog/ESP8266TimerInterrupt

// Select a Timer Clock
#define USING_TIM_DIV1 false  // for shortest and most accurate timer
#define USING_TIM_DIV16 false // for medium time and medium accurate timer
#define USING_TIM_DIV256 true // for longest timer but least accurate. Default

// Init ESP8266 only and only Timer 1
ESP8266Timer ITimer;

void IRAM_ATTR TimerHandler()
{
  // Doing something here inside ISR
  secPassed = true;
}

#define TIMER_INTERVAL_MS 1000

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

  taskManager.scheduleFixedRate(200, []
                                {
                                  if (secPassed)
                                  {
                                    washing_machine_controller.loop();
                                    watch_dog.reset();
                                    secPassed = false;
                                  }
                                });

  taskManager.scheduleFixedRate(100, []
                                { buttons.loop(); });

  taskManager.scheduleFixedRate(1, []
                                { rest_api_server.loop(); });

  // Interval in microsecs
  if (ITimer.attachInterruptInterval(TIMER_INTERVAL_MS * 1000, TimerHandler))
  {
    Serial.print(F("Starting  ITimer OK, millis() = "));
    Serial.println(millis());
  }
  else
  {
    Serial.println(F("Can't set ITimer correctly. Select another freq. or interval"));
  }

  display.init();
  watch_dog.setup();
  rest_api_server.setup();
}

void TaskScheduler::loop()
{
  taskManager.runLoop();
}

TaskScheduler task_scheduler;