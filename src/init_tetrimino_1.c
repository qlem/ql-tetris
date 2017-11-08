//
// Created by qlem on 15/07/17.
//

#include "../inc/tetris.h"

t_tetrimino     *get_last_tetrimino(t_tetris *tetris)
{
    t_tetrimino     *tmp;

    tmp = tetris->v_game->l_tetri;
    while (tmp->next)
        tmp = tmp->next;
    return (tmp);
}

void        add_tetrimino(t_tetris *tetris, char *buffer)
{
    t_tetrimino     *new;

    new = malloc(sizeof(t_tetrimino));
    if (new == NULL)
        return;
    set_new_tetrimino(new, buffer);
    new->position.s_x = 0;
    new->position.e_x = 0;
    new->position.s_y = 0;
    new->position.e_y = 0;
    new->next = NULL;
    if (tetris->v_game->nb_tetri > 0)
        get_last_tetrimino(tetris)->next = new;
    else
        tetris->v_game->l_tetri = new;
    tetris->v_game->nb_tetri++;
}