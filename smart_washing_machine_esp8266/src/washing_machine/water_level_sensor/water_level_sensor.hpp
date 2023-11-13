#ifndef WATERLEVELSENSOR_H
#define WATERLEVELSENSOR_H

#include <Arduino.h>
#include "GPIO_CONFIG.hpp"

class WaterLevelSensor {
  public:
    WaterLevelSensor();
    void setup();
    void loop();
};

extern WaterLevelSensor water_level_sensor;

#endif