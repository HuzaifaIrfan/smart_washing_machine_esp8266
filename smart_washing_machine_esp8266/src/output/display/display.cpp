
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

void Display::display_current_state(int current_state_index){
    // set_cursor(8, 1);
    // print(String(WASHING_MACHINE_STATES_LABEL[current_state_index]));
}

void Display::display_current_routine(int machine_routine[][4], short current_routine_state_pointer)
{

    // set_cursor(0, 0);

    // for (int i = 0; i < 16; ++i)
    // {
    //     short state_index = machine_routine[i][0];
    //     if (i < current_routine_state_pointer)
    //     {
    //         print(">");
    //     }
    //     else
    //     {
    //         print(String(WASHING_MACHINE_STATES_CHAR[state_index]));
    //     }
    // }


}

Display display;