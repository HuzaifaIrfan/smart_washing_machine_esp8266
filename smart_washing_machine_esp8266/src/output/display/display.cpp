
#include "display.hpp"
#include "output/LABELS.hpp"


// LiquidCrystal lcd(LCD_RS_PIN, LCD_EN_PIN, LCD_D0_PIN, LCD_D1_PIN, LCD_D2_PIN, LCD_D3_PIN);


Display::Display()
{
}

void Display::setup()
{
    // init();
    // set_cursor_and_print("Smart Washer", 0, 0);
    // set_cursor_and_print("Huzaifa Irfan", 0, 1);
}

void Display::init()
{
    // lcd.begin(16, 2);
}

void Display::loop()
{
}

void Display::set_cursor(uint8_t col, uint8_t row)
{
    // lcd.setCursor(col, row);
}

void Display::print(String message)
{
    // lcd.print(message);
}

void Display::set_cursor_and_print(String message, uint8_t col, uint8_t row)
{
    // set_cursor(col, row);
    // print(message);
}

void Display::display_count_down(int count_down){
    // set_cursor(0, 1);
    // print(String(count_down)+"   ");
}

void Display::display_current_task(int current_task_index){
    // set_cursor(8, 1);
    // print(String(WASHING_MACHINE_TASKS_LABEL[current_task_index]));
}

void Display::display_current_task_sequence(int washing_machine_task_sequence[][4], short current_task_sequence_pointer)
{

    // set_cursor(0, 0);

    // for (int i = 0; i < 16; ++i)
    // {
    //     short task_index = washing_machine_task[i][0];
    //     if (i < current_task_sequence_pointer)
    //     {
    //         print(">");
    //     }
    //     else
    //     {
    //         print(String(WASHING_MACHINE_TASKS_CHAR[task_index]));
    //     }
    // }


}

Display display;