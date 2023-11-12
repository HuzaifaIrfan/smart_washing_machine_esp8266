
#include "watch_dog.hpp"

WatchDog::WatchDog()
{
}

void WatchDog::setup()
{
    // ESP.wdtDisable(); // Disable WDT
    // ESP.wdtEnable(4000); // Enable WDT with a timeout of 4 seconds
    Serial.println("WDT Enabled");
}

void WatchDog::reset()
{
    // ESP.wdtFeed();
}

WatchDog watch_dog;