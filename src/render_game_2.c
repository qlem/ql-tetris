//
// Created by qlem on 15/07/17.
//

#include "../inc/tetris.h"

void        render_current_tetrimino(t_tetris *tetris)
{
    int     x;
    int     y;
    int     i;
    int     j;

    y = -1;
    i = tetris->v_game->c_tetri->position.s_y + 1;
    while (++y < tetris->v_game->c_tetri->height)
    {
        x = -1;
        j = tetris->v_game->c_tetri->position.s_x;
        while (++x < tetris->v_game->c_tetri->width)
        {
            if (tetris->v_game->c_tetri->matrix[y][x] != -1)
            {
                caca_set_color_ansi(tetris->canvas, CACA_TRANSPARENT, get_color(tetris->v_game->c_tetri->matrix[y][x]));
                caca_put_str(tetris->canvas, j * 2 + 24, i, "  ");
                caca_set_color_ansi(tetris->canvas, CACA_DEFAULT, CACA_DEFAULT);
            }
            j++;
        }
        i++;
    }
}

void        render_grid_only(t_tetris *tetris)
{
    int     x;
    int     y;

    y = -1;
    caca_set_color_ansi(tetris->canvas, CACA_TRANSPARENT, get_color(tetris->menu->subm_color->tab_color[tetris->menu->subm_color->p_index].color));
    caca_draw_box(tetris->canvas, 23, 0, 22, 22, ' ');
    caca_set_color_ansi(tetris->canvas, CACA_DEFAULT, CACA_DEFAULT);
    while (++y < GRID_H)
    {
        x = -1;
        while (++x < GRID_W)
        {
            if (tetris->v_game->grid[y][x] != -1)
            {
                caca_set_color_ansi(tetris->canvas, CACA_TRANSPARENT, get_color(tetris->v_game->grid[y][x]));
                caca_put_str(tetris->canvas, x * 2 + 24, y + 1, "  ");
                caca_set_color_ansi(tetris->canvas, CACA_DEFAULT, CACA_DEFAULT);
            }
        }
    }
}

void        render_grid(t_tetris *tetris)
{
    render_grid_only(tetris);
    if (tetris->state != OVER)
        render_current_tetrimino(tetris);
}