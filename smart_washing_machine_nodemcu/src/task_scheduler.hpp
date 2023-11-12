#ifndef _TaskScheduler_H_
#define _TaskScheduler_H_

#include <Arduino.h>

class TaskScheduler
{
private:
public:
    TaskScheduler();

    void setup();
    void loop();
};

extern TaskScheduler task_scheduler;

#endif