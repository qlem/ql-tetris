//
// Created by qlem on 14/07/17.
//

#include "../inc/tetris.h"

void    set_event(t_tetris *tetris)
{
    caca_event_t    caca_event;

    caca_get_event(tetris->display, CACA_EVENT_KEY_PRESS | CACA_EVENT_KEY_RELEASE | CACA_EVENT_QUIT, &caca_event, 0);
    if (caca_get_event_type(&caca_event) == CACA_EVENT_QUIT)
        tetris->event = CLOSE;
    else if (caca_get_event_type(&caca_event) == CACA_EVENT_KEY_PRESS)
    {
        if (caca_get_event_key_ch(&caca_event) == CACA_KEY_UP)
            tetris->event = UP;
        else if (caca_get_event_key_ch(&caca_event) == CACA_KEY_DOWN)
            tetris->event = DOWN;
        else if (caca_get_event_key_ch(&caca_event) == CACA_KEY_RIGHT)
            tetris->event = RIGHT;
        else if (caca_get_event_key_ch(&caca_event) == CACA_KEY_LEFT)
            tetris->event = LEFT;
        else if (caca_get_event_key_ch(&caca_event) == CACA_KEY_RETURN)
            tetris->event = ENTER;
        else if (caca_get_event_key_ch(&caca_event) == CACA_KEY_ESCAPE)
            tetris->event = ESCAPE;
        else if (caca_get_event_key_ch(&caca_event) == 'r')
            tetris->event = RESTART;
        else
            tetris->event = KEY_PRESSED;
    }
    else if (caca_get_event_type(&caca_event) == CACA_EVENT_KEY_RELEASE)
        tetris->event = NO_PRESSED;
}