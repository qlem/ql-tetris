//
// Created by qlem on 29/10/17.
//

#include "../inc/tetris.h"

enum caca_color get_color(int color)
{
    if (color == 1)
        return CACA_LIGHTBLUE;
    else if (color == 2)
        return CACA_GREEN;
    else if (color == 3)
        return CACA_CYAN;
    else if (color == 4)
        return CACA_RED;
    else if (color == 5)
        return CACA_MAGENTA;
    else if (color == 6)
        return CACA_BROWN;
    else if (color == 7)
        return CACA_YELLOW;
    return CACA_BLACK;
}