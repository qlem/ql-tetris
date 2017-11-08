//
// Created by qlem on 15/07/17.
//

#include "../inc/tetris.h"

int     get_x_right_solid(t_tetrimino *tmp, int y)
{
    int     x;

    x = tmp->width;
    while (--x >= 0)
    {
        if (tmp->matrix[y][x] != -1)
            return (x);
    }
    return (0);
}

bool            move_right(t_tetris *tetris)
{
    t_tetrimino     *tmp;
    int             x;
    int             y;
    int             i;

    i = 0;
    tmp = tetris->v_game->c_tetri;
    if (tmp->position.e_x + 1 > GRID_W - 1)
        return (false);
    y = tmp->position.s_y - 1;
    while (++y <= tmp->position.e_y)
    {
        x = tmp->position.s_x + get_x_right_solid(tmp, i);
        if (tetris->v_game->grid[y][x + 1] != -1)
            return (false);
        i++;
    }
    tmp->position.s_x++;
    tmp->position.e_x++;
    return (true);
}