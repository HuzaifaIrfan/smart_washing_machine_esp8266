#include "utils.hpp"

int validate(short tmp_value, int maximum_value, int minimum_value)
{
    if (tmp_value > maximum_value)
    {
        return maximum_value;
    }

    if (tmp_value < minimum_value)
    {
        return minimum_value;
    }

    return tmp_value;
}