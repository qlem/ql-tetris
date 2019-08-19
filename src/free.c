//
// Created by qlem on 19/07/17.
//

#include "../inc/tetris.h"

int         **free_grid(t_tetris *tetris)
{
    int     y;

    y = -1;
    while (++y < GRID_H)
        free(tetris->v_game->grid[y]);
    free(tetris->v_game->grid);
    return (0);
}

int         free_matrix(t_tetrimino *tetrimino)
{
    int     y;

    y = -1;
    while (++y < tetrimino->height)
        free(tetrimino->matrix[y]);
    free(tetrimino->matrix);
    return (0);
}

int         free_tetrimino_list(t_tetris *tetris)
{
    t_tetrimino     *tmp;
    t_tetrimino     *del;
    int             i;

    i = -1;
    tmp = tetris->v_game->l_tetri;
    while (++i < tetris->v_game->nb_tetri)
    {
        free_matrix(tmp);
        del = tmp;
        tmp = tmp->next;
        free(del);
    }
    return (0);
}

int     free_mem(t_tetris *tetris)
{
    free_audio(tetris);
    caca_free_canvas(tetris->canvas);
    caca_free_display(tetris->display);
    free(tetris->menu->subm_color);
    free(tetris->menu);
    free_grid(tetris);
    free(tetris->v_game->timer_game);
    free_tetrimino_list(tetris);
    free(tetris->v_game);
    free(tetris->timer_core);
    free(tetris->hs_path);
    return (0);
}