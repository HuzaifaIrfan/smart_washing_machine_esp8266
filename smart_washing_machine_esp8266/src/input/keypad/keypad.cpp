
#include "keypad.hpp"

// void change_to_new_task(){
// int new_washing_machine_task_sequence[16][4] = {
//     {MACHINE_WAITING_TASK, 1, 0, 0},
//     {MACHINE_WAITING_TASK, 1, 0, 0},
//     {MACHINE_WAITING_TASK, 1, 0, 0},
//     {MACHINE_WAITING_TASK, 1, 0, 0},
//     {MACHINE_WAITING_TASK, 1, 0, 0},
//     {MACHINE_WAITING_TASK, 1, 0, 0},
//     {MACHINE_WAITING_TASK, 1, 0, 0},
//     {MACHINE_WAITING_TASK, 1, 0, 0},
//     {MACHINE_WAITING_TASK, 1, 0, 0},
//     {MACHINE_WAITING_TASK, 1, 0, 0},
//     {MACHINE_WAITING_TASK, 1, 0, 0},
//     {MACHINE_WAITING_TASK, 1, 0, 0},
//     {MACHINE_WAITING_TASK, 1, 0, 0},
//     {MACHINE_WAITING_TASK, 1, 0, 0},
//     {MACHINE_WAITING_TASK, 1, 0, 0},
//     {MACHINE_WAITING_TASK, 1, 0, 0}};

//     change_washing_machine_task_sequence(new_washing_machine_task_sequence);
// }

Keypad::Keypad(Display *display, WashingMachineController *washing_machine_controller) : display(display), washing_machine_controller(washing_machine_controller)
{
}

void Keypad::setup()
{
}

void Keypad::loop()
{
  // //     display->set_cursor(9, 1);        // move cursor to second line "1" and 9 spaces over
  // // display->print(String(millis() / 1000)); // display seconds elapsed since power-up

  // display->set_cursor(9, 1);    // move to the begining of the second line
  // lcd_key = read_LCD_buttons(); // read the buttons

  // switch (lcd_key) // depending on which button was pushed, we perform an action
  // {
  // case btnSELECT:
  // {
  //   // display->print("SELECT");
  //   Serial.println("Run");
  //   washing_machine_controller->run();
  //   break;
  // }
  // case btnLEFT:
  // {
  //   // display->print("LEFT   ");
  //   Serial.println("Pause");
  //   washing_machine_controller->pause();
  //   break;
  // }

  // case btnUP:
  // {
  //   // display->print("UP    ");
  //   Serial.println("Increase Current Task");
  //   washing_machine_controller->increase_current_task_index();
  //   break;
  // }
  // case btnDOWN:
  // {
  //   // display->print("DOWN  ");
  //   Serial.println("Decrease Current Task");
  //   washing_machine_controller->decrease_current_task_index();
  //   break;
  // }
  // case btnRIGHT:
  // {
  //   // display->print("RIGHT ");
  //   Serial.println("Reset");
  //   // change_to_new_task();
  //   washing_machine_controller->reset();
  //   break;
  // }

    // case btnNONE:
    // {
    //   display->print("NONE  ");
    //   break;
    // }
  // }
}




Keypad keypad(&display, &washing_machine_controller);