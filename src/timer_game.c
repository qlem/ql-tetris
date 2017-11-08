//
// Created by qlem on 15/07/17.
//

#include "../inc/tetris.h"

void        update_timer_game(t_tetris *tetris)
{
    struct timespec     tp;
    time_t              diff;

    clock_gettime(CLOCK_REALTIME, &tp);
    diff = tp.tv_sec - tetris->v_game->timer_game->ref;
    if (tetris->v_game->timer_game->sec + diff > 59)
    {
        tetris->v_game->timer_game->sec = 0;
        if (tetris->v_game->timer_game->min + 1 > 59)
        {
            tetris->v_game->timer_game->min = 0;
            tetris->v_game->timer_game->hour++;
        }
        else
            tetris->v_game->timer_game->min++;
    }
    else
        tetris->v_game->timer_game->sec += diff;
    tetris->v_game->timer_game->ref = tp.tv_sec;
}

void        set_ref_timer_game(t_tetris *tetris)
{
    struct timespec     tp;

    clock_gettime(CLOCK_REALTIME, &tp);
    tetris->v_game->timer_game->ref = tp.tv_sec;
}

t_timer_game     *malloc_timer_game(void)
{
    t_timer_game     *timer;

    timer = malloc(sizeof(t_timer_game));
    if (timer == NULL)
        return (NULL);
    timer->sec = 0;
    timer->min = 0;
    timer->hour = 0;
    timer->ref = 0;
    return (timer);
}

