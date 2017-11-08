//
// Created by qlem on 16/07/17.
//

#include "../inc/tetris.h"

int         **build_new_matrix(t_tetrimino *tetrimino)
{
    int     **n_matrix;
    int     i;
    int     j;

    n_matrix = malloc(sizeof(int *) * tetrimino->width);
    if (n_matrix == NULL)
        return (NULL);
    i = -1;
    while (++i < tetrimino->width)
    {
        n_matrix[i] = malloc(sizeof(int) * tetrimino->height);
        if (n_matrix[i] == NULL)
            return (NULL);
        j = -1;
        while (++j < tetrimino->height)
            n_matrix[i][j] = -1;
    }
    return (n_matrix);
}

bool        rotate(t_tetris *tetris)
{
    t_tetrimino     *tmp;
    int             **n_matrix;
    int             y;
    int             x;
    int             a;

    tmp = tetris->v_game->c_tetri;
    if (!check_rotate(tetris))
        return (false);
    n_matrix = build_new_matrix(tmp);
    y = -1;
    while (++y < tmp->width)
    {
        x = -1;
        while (++x < tmp->height)
            n_matrix[y][x] = tmp->matrix[tmp->height - 1 - x][y];
    }
    free_matrix(tmp);
    tmp->matrix = n_matrix;
    a = tmp->width;
    tmp->width = tmp->height;
    tmp->height = a;
    tmp->position.e_x = tmp->position.s_x + (tmp->width - 1);
    tmp->position.e_y = tmp->position.s_y + (tmp->height - 1);
    return (true);
}