//
// Created by qlem on 15/07/17.
//

#include "../inc/tetris.h"

int     get_y_solid(t_tetrimino *tmp, int x)
{
    int     y;

    y = tmp->height;
    while (--y >= 0)
    {
        if (tmp->matrix[y][x] > -1)
            return (y);
    }
    return (0);
}

bool            move_down(t_tetris *tetris)
{
    t_tetrimino     *tmp;
    int             x;
    int             y;
    int             j;

    j = 0;
    tmp = tetris->v_game->c_tetri;
    if (tmp->position.e_y + 1 > GRID_H - 1)
        return (false);
    x = tmp->position.s_x - 1;
    while (++x <= tmp->position.e_x)
    {
        y = tmp->position.s_y + get_y_solid(tmp, j);
        if (tetris->v_game->grid[y + 1][x] > -1)
            return (false);
        j++;
    }
    tmp->position.s_y++;
    tmp->position.e_y++;
    return (true);
}