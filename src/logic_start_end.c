//
// Created by qlem on 14/07/17.
//

#include "../inc/tetris.h"

void        clear_grid(t_tetris *tetris)
{
    int     y;
    int     x;

    y = -1;
    while (++y < GRID_H)
    {
        x = -1;
        while (++x < GRID_W)
            tetris->v_game->grid[y][x] = -1;
    }
}

void    restart_game(t_tetris *tetris)
{
    clear_grid(tetris);
    tetris->v_game->c_tetri = NULL;
    tetris->v_game->n_tetri = NULL;
    tetris->v_game->c_tetri = get_tetrimino(tetris);
    tetris->v_game->n_tetri = get_tetrimino(tetris);
    set_ref_time_move(tetris);
    set_ref_timer_game(tetris);
    set_ref_time_fall(tetris);
    tetris->v_game->score = 0;
    tetris->v_game->h_score = load_high_score(tetris->hs_path);
    tetris->v_game->nb_lines = 0;
    tetris->v_game->level = 0;
    tetris->v_game->timer_game->sec = 0;
    tetris->v_game->timer_game->hour = 0;
    tetris->v_game->timer_game->min = 0;
}

void        end_logic(t_tetris *tetris)
{
    if (tetris->v_game->score > tetris->v_game->h_score)
        write_new_high_score(tetris->v_game->score, tetris->hs_path);
    if (tetris->event == ESCAPE && get_timing(tetris, UI))
    {
        Mix_PlayChannel(-1, tetris->audio->sounds[2], 0);
        tetris->state = QUIT;
    }
    else if (tetris->event == RESTART && get_timing(tetris, UI))
    {
        Mix_PlayChannel(-1, tetris->audio->sounds[2], 0);
        Mix_PlayMusic(tetris->audio->music, -1);
        restart_game(tetris);
        tetris->state = GAME;
    }
    render_end(tetris);
}

void        start_logic(t_tetris *tetris)
{
    if (tetris->event != NO_PRESSED && get_timing(tetris, UI))
    {
        tetris->state = GAME;
        set_ref_timer_game(tetris);
        set_ref_time_move(tetris);
        set_ref_time_fall(tetris);
        Mix_PlayChannel(-1, tetris->audio->sounds[2], 0);
        Mix_PlayMusic(tetris->audio->music, -1);
    }
    render_start(tetris);
}