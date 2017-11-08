//
// Created by qlem on 15/07/17.
//

#include "../inc/tetris.h"

double      delta_tab[10] = {
        1000000000.0,
        911111111.1111,
        822222222.2222,
        733333333.3333,
        644444444.4444,
        555555555.5555,
        466666666.6666,
        377777777.7777,
        288888888.8888,
        200000000.0
};


double      get_delta(t_tetris *tetris, e_timer_t timer_type)
{
    double      delta;

    delta = 0;
    if (timer_type == FALL)
    {
        if (tetris->event == DOWN)
            delta =  50000000.0;
        else if (tetris->v_game->level <= 9)
            delta = delta_tab[tetris->v_game->level];
        else
            delta = delta_tab[9];
    }
    else if (timer_type == MOVE)
        delta = 100000000;
    else if (timer_type == UI)
        delta = 200000000;
    return (delta);
}

bool        get_timing(t_tetris *tetris, e_timer_t timer_type)
{
    struct timespec     tp;
    double              now;
    double              delta;

    clock_gettime(CLOCK_REALTIME, &tp);
    now = (tp.tv_sec * BILLION) + tp.tv_nsec;

    delta = get_delta(tetris, timer_type);

    if (timer_type == FALL && now - tetris->timer_core->ref_time_fall > delta)
    {
        tetris->timer_core->ref_time_fall = now;
        return (true);
    }

    else if (timer_type == MOVE && now - tetris->timer_core->ref_time_move > delta)
    {
        tetris->timer_core->ref_time_move = now;
        return (true);
    }

    else if (timer_type == UI && now - tetris->timer_core->ref_time_ui > delta)
    {
        tetris->timer_core->ref_time_ui = now;
        return (true);
    }
    return (false);
}

void        set_ref_time_move(t_tetris *tetris)
{
    struct timespec     tp;

    clock_gettime(CLOCK_REALTIME, &tp);
    tetris->timer_core->ref_time_move = (tp.tv_sec * BILLION) + tp.tv_nsec;
}

void        set_ref_time_ui(t_tetris *tetris)
{
    struct timespec tp;

    clock_gettime(CLOCK_REALTIME, &tp);
    tetris->timer_core->ref_time_ui = (tp.tv_sec * BILLION) + tp.tv_nsec;
}

void        set_ref_time_fall(t_tetris *tetris)
{
    struct timespec     tp;

    clock_gettime(CLOCK_REALTIME, &tp);
    tetris->timer_core->ref_time_fall = (tp.tv_sec * BILLION) + tp.tv_nsec;
}

t_timer_core    *malloc_timer_core(void)
{
    t_timer_core    *timer_core;

    timer_core = malloc(sizeof(t_timer_core));
    if (!timer_core)
        return (NULL);
    timer_core->ref_time_move = 0;
    timer_core->ref_time_ui = 0;
    timer_core->ref_time_fall = 0;
    return (timer_core);
}