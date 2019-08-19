//
// Created by qlem on 15/07/17.
//

#include "../inc/tetris.h"

int         **malloc_grid(void)
{
    int     **grid;
    int     i;
    int     j;

    i = -1;
    grid = malloc(sizeof(int *) * GRID_H);
    while (++i < GRID_H)
    {
        j = -1;
        grid[i] = malloc(sizeof(int) * GRID_W);
        while (++j < GRID_W)
            grid[i][j] = -1;
    }
    return (grid);
}

t_v_game      *malloc_var_game(void)
{
    t_v_game      *new;

    new = malloc(sizeof(t_v_game));
    if (new == NULL)
        return (NULL);
    new->score = 0;
    new->h_score = 0;
    new->level = 0;
    new->nb_lines = 0;
    new->nb_tetri = 0;
    new->grid = malloc_grid();
    new->timer_game = malloc_timer_game();
    new->l_tetri = NULL;
    new->n_tetri = NULL;
    new->c_tetri = NULL;
    return (new);
}