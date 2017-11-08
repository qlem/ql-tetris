//
// Created by qlem on 14/07/17.
//

#include "../inc/tetris.h"

void        render_data(t_tetris *tetris)
{
    caca_put_str(tetris->canvas, 2, 12, "Timer");
    caca_put_str(tetris->canvas, 2, 14, "Score");
    caca_put_str(tetris->canvas, 2, 16, "Level");
    caca_put_str(tetris->canvas, 2, 18, "Lines");
    caca_put_str(tetris->canvas, 2, 20, "H. score");
    caca_set_attr(tetris->canvas, CACA_BOLD);
    caca_printf(tetris->canvas, 12, 12, "%02d:%02d:%02d", tetris->v_game->timer_game->hour, tetris->v_game->timer_game->min, tetris->v_game->timer_game->sec);
    caca_printf(tetris->canvas, 14, 14, "%6d", tetris->v_game->score);
    caca_printf(tetris->canvas, 14, 16, "%6d", tetris->v_game->level);
    caca_printf(tetris->canvas, 14, 18, "%6d", tetris->v_game->nb_lines);
    caca_printf(tetris->canvas, 14, 20, "%6d", tetris->v_game->h_score);
    caca_unset_attr(tetris->canvas, CACA_BOLD);
}

void        render_next(t_tetris *tetris)
{
    int     x;
    int     y;
    int     i;
    int     j;

    y = -1;
    caca_set_color_ansi(tetris->canvas, CACA_TRANSPARENT, get_color(tetris->menu->subm_color->tab_color[tetris->menu->subm_color->p_index].color));
    caca_draw_box(tetris->canvas, 0, 0, 22, 11, ' ');
    caca_set_color_ansi(tetris->canvas, CACA_DEFAULT, CACA_DEFAULT);
    i = 5 - tetris->v_game->n_tetri->height / 2;
    while (++y < tetris->v_game->n_tetri->height)
    {
        x = -1;
        j = 5 - tetris->v_game->n_tetri->width / 2;
        while (++x < tetris->v_game->n_tetri->width)
        {
            if (tetris->v_game->n_tetri->matrix[y][x] != -1)
            {
                caca_set_color_ansi(tetris->canvas, CACA_TRANSPARENT, get_color(tetris->v_game->n_tetri->matrix[y][x]));
                caca_put_str(tetris->canvas, j * 2 + 1, i, "  ");
                caca_set_color_ansi(tetris->canvas, CACA_DEFAULT, CACA_DEFAULT);
            }
            j++;
        }
        i++;
    }
}

void            render_game(t_tetris *tetris)
{
    render_grid(tetris);
    render_next(tetris);
    render_data(tetris);
}