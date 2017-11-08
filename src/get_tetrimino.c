//
// Created by qlem on 15/07/17.
//

#include "../inc/tetris.h"

int     get_random_nbr(int min, int max)
{
    int     nbr;

    nbr = rand() % (max + 1 - min) + min;
    return (nbr);
}

t_tetrimino     *get_tetrimino(t_tetris *tetris)
{
    t_tetrimino     *tmp;
    int             i;
    int             rand;

    i = 0;
    tmp = tetris->v_game->l_tetri;
    rand = get_random_nbr(1, tetris->v_game->nb_tetri);
    while (++i < rand)
        tmp = tmp->next;
    if (tetris->v_game->c_tetri && tmp == tetris->v_game->c_tetri)
        return (get_tetrimino(tetris));
    tmp->position.s_x = (GRID_W / 2) - (tmp->width / 2);
    tmp->position.s_y = 0;
    tmp->position.e_x = tmp->position.s_x + tmp->width - 1;
    tmp->position.e_y = tmp->position.s_y + tmp->height - 1;
    return (tmp);
}