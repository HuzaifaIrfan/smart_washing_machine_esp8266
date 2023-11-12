
#include "buttons.hpp"

Buttons::Buttons(ezButton *hold_skip_input_button, WashingMachineController *washing_machine_controller) : hold_skip_input_button(hold_skip_input_button), washing_machine_controller(washing_machine_controller)
{
}

void Buttons::setup()
{
    hold_skip_input_button->setDebounceTime(500);
}

void Buttons::loop()
{
    hold_skip_input_button->loop();
    check();
}

void Buttons::check()
{

    if (hold_skip_input_button->isPressed())
    {
        washing_machine_controller->hold();
        // display.set_cursor_and_print("H1", 14, 0);
        Serial.println("Hold");
    }
    if (hold_skip_input_button->isReleased())
    {
        washing_machine_controller->skip();
        // display.set_cursor_and_print("H0", 14, 0);
        Serial.println("Skip");
    }
}

ezButton hold_skip_input_button(HOLD_SKIP_INPUT_PIN);

Buttons buttons(&hold_skip_input_button, &washing_machine_controller);