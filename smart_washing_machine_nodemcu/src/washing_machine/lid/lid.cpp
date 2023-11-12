
#include "lid.hpp"

volatile bool Lid::lid_open_or_vibration_interrupted = false;

Lid::Lid(short pin) : pin(pin)
{
}

void Lid::setup()
{
  pinMode(pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pin), lid_open_or_dryer_vibration_switch_interrupt_service_routine, RISING);
}

void ICACHE_RAM_ATTR Lid::lid_open_or_dryer_vibration_switch_interrupt_service_routine() {
  lid_open_or_vibration_interrupted = true;
}

// void Lid::lid_open_or_dryer_vibration_switch_interrupt_service_routine()
// {
//   lid_open_or_vibration_interrupted = true;
// }

void Lid::loop()
{
  if (digitalRead(pin) == 1)
  {
    lid_open_or_vibration_interrupted = true;
  }
  Serial.println("Lid: "+String(lid_open_or_vibration_interrupted));
}

void Lid::close()
{
  if (digitalRead(pin) == 0)
  {
    lid_open_or_vibration_interrupted = false;
  }
}

bool Lid::is_closed()
{
  loop();
  return not lid_open_or_vibration_interrupted;
}

Lid lid(LID_INPUT_PIN);
