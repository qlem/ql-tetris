//
// Created by qlem on 14/07/17.
//

#include "../inc/tetris.h"

void        render_sub_menu(t_tetris *tetris)
{
    int     i;
    int     x;
    int     y;

    i = -1;
    y = 8;
    x = WIDTH / 2 - (int)strlen("color x") / 2;
    while (++i < tetris->menu->subm_color->nb_color)
    {
        caca_set_color_ansi(tetris->canvas, get_color(tetris->menu->subm_color->tab_color[i].color), CACA_TRANSPARENT);
        if (tetris->menu->subm_color->p_index == i)
        {
            caca_set_color_ansi(tetris->canvas, CACA_TRANSPARENT, get_color(tetris->menu->subm_color->tab_color[i].color));
            caca_put_str(tetris->canvas, x, y, tetris->menu->subm_color->tab_color[i].name);
        }
        else
            caca_put_str(tetris->canvas, x, y, tetris->menu->subm_color->tab_color[i].name);
        caca_set_color_ansi(tetris->canvas, CACA_DEFAULT, CACA_DEFAULT);
        y++;
    }
}

void        render_option(t_tetris *tetris, int index, int y)
{
    int     x;

    x = WIDTH / 2 - (int)strlen(tetris->menu->tab_elem[index].name) / 2;
    if (tetris->menu->p_index == index && !tetris->menu->opt_color)
    {
        caca_set_attr(tetris->canvas, CACA_BOLD);
        caca_set_color_ansi(tetris->canvas, CACA_YELLOW, CACA_TRANSPARENT);
        caca_put_str(tetris->canvas, x, y, tetris->menu->tab_elem[index].name);
        caca_set_color_ansi(tetris->canvas, CACA_DEFAULT, CACA_DEFAULT);
        caca_unset_attr(tetris->canvas, CACA_BOLD);
    }
    else
        caca_put_str(tetris->canvas, x, y, tetris->menu->tab_elem[index].name);
}

void        render_music_option(t_tetris *tetris, int y)
{
    char    *string;
    int     x;

    if (tetris->audio->active_music)
        string = "Music ON";
    else
        string = "Music OFF";
    x = WIDTH / 2 - (int)strlen("Music XXX") / 2;
    if (tetris->menu->p_index == 3 && !tetris->menu->opt_color)
    {
        caca_set_attr(tetris->canvas, CACA_BOLD);
        caca_set_color_ansi(tetris->canvas, CACA_YELLOW, CACA_TRANSPARENT);
        caca_put_str(tetris->canvas, x, y, string);
        caca_set_color_ansi(tetris->canvas, CACA_DEFAULT, CACA_DEFAULT);
        caca_unset_attr(tetris->canvas, CACA_BOLD);
    }
    else
        caca_put_str(tetris->canvas, x, y, string);
}

void        render_menu(t_tetris *tetris)
{
    render_option(tetris, 0, 2);
    render_option(tetris, 1, 4);
    render_option(tetris, 2, 6);
    render_sub_menu(tetris);
    render_music_option(tetris, 16);
    render_option(tetris, 4, 19);
}