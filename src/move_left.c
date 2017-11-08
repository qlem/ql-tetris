//
// Created by qlem on 15/07/17.
//

#include "../inc/tetris.h"

int     get_x_left_solid(t_tetrimino *tmp, int y)
{
    int     x;

    x = -1;
    while (++x < tmp->width)
    {
        if (tmp->matrix[y][x] != -1)
            return (x);
    }
    return (0);
}

bool            move_left(t_tetris *tetris)
{
    t_tetrimino     *tmp;
    int             x;
    int             y;
    int             i;

    i = 0;
    tmp = tetris->v_game->c_tetri;
    if (tmp->position.s_x - 1 < 0)
        return (false);
    y = tmp->position.s_y - 1;
    while (++y <= tmp->position.e_y)
    {
        x = tmp->position.s_x + get_x_left_solid(tmp, i);
        if (tetris->v_game->grid[y][x - 1] != -1)
            return (false);
        i++;
    }
    tmp->position.s_x--;
    tmp->position.e_x--;
    return (true);
}