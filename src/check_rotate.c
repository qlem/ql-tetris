//
// Created by qlem on 16/07/17.
//

#include "../inc/tetris.h"

bool        check_rotate_four(t_tetris *tetris)
{
    t_tetrimino     *tmp;
    int             x;
    int             y;

    tmp = tetris->v_game->c_tetri;
    y = tmp->position.s_y - 1;
    while (++ y <= tmp->position.e_y)
    {
        x = tmp->position.e_x - 1;
        while (++x <= tmp->position.e_x + (tmp->height - tmp->width))
        {
            if (tetris->v_game->grid[y][x] != -1)
                return (false);
        }
    }
    return (true);
}

bool        check_rotate_three(t_tetris *tetris)
{
    t_tetrimino     *tmp;
    int             x;
    int             y;

    tmp = tetris->v_game->c_tetri;
    y = tmp->position.e_y - 1;
    while (++ y <= tmp->position.e_y + (tmp->width - tmp->height))
    {
        x = tmp->position.s_x - 1;
        while (++x <= tmp->position.e_x)
        {
            if (tetris->v_game->grid[y][x] != -1)
                return (false);
        }
    }
    return (true);
}

bool        check_rotate_two(t_tetris *tetris)
{
    t_tetrimino     *tmp;

    tmp = tetris->v_game->c_tetri;
    if (tmp->width > tmp->height && tmp->position.e_y + (tmp->width - tmp->height) > GRID_H - 1)
        return (false);
    else if (tmp->position.e_x + (tmp->height - tmp->width) > GRID_W - 1)
        return (false);
    return (true);
}

bool        check_rotate_one(t_tetris *tetris)
{
    t_tetrimino     *tmp;
    int             y;
    int             x;
    int             i;
    int             j;

    y = -1;
    tmp = tetris->v_game->c_tetri;
    i = tmp->position.s_y;
    while (++y < tmp->height)
    {
        x = -1;
        j = tmp->position.s_x;
        while (++x < tmp->width)
        {
            if (tmp->matrix[y][x] == -1 && tetris->v_game->grid[i][j] != -1)
                return (false);
            j++;
        }
        i++;
    }
    return (true);
}

bool        check_rotate(t_tetris *tetris)
{
    if (!check_rotate_one(tetris))
        return (false);
    if (!check_rotate_two(tetris))
        return (false);
    if (tetris->v_game->c_tetri->width > tetris->v_game->c_tetri->height)
    {
        if (!check_rotate_three(tetris))
            return (false);
    }
    else
    {
        if (!check_rotate_four(tetris))
            return (false);
    }
    return (true);
}