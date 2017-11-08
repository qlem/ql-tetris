//
// Created by qlem on 14/07/17.
//

#include "../inc/tetris.h"

void        up_event(t_tetris *tetris)
{
    Mix_PlayChannel(-1, tetris->audio->sounds[2], 0);
    if (tetris->menu->opt_color)
    {
        if (tetris->menu->subm_color->p_index == 0)
            tetris->menu->subm_color->p_index = tetris->menu->subm_color->nb_color - 1;
        else
            tetris->menu->subm_color->p_index--;
    }
    else
    {
        if (tetris->menu->p_index == 0)
            tetris->menu->p_index = tetris->menu->nb_elem - 1;
        else
            tetris->menu->p_index--;
    }
}

void        down_event(t_tetris *tetris)
{
    Mix_PlayChannel(-1, tetris->audio->sounds[2], 0);
    if (tetris->menu->opt_color)
    {
        if (tetris->menu->subm_color->p_index == tetris->menu->subm_color->nb_color - 1)
            tetris->menu->subm_color->p_index = 0;
        else
            tetris->menu->subm_color->p_index++;
    }
    else
    {
        if (tetris->menu->p_index == tetris->menu->nb_elem - 1)
            tetris->menu->p_index = 0;
        else
            tetris->menu->p_index++;
    }
}

void        enter_event(t_tetris *tetris)
{
    Mix_PlayChannel(-1, tetris->audio->sounds[2], 0);
    if (tetris->menu->tab_elem[tetris->menu->p_index].id == 0)
    {
        if (tetris->audio->active_music)
            Mix_ResumeMusic();
        set_ref_time_move(tetris);
        set_ref_timer_game(tetris);
        set_ref_time_fall(tetris);
        tetris->state = GAME;
    }
    else if (tetris->menu->tab_elem[tetris->menu->p_index].id == 1)
    {
        Mix_RewindMusic();
        if (tetris->audio->active_music)
            Mix_ResumeMusic();
        tetris->menu->p_index = 0;
        restart_game(tetris);
        tetris->state = GAME;
    }
    else if (tetris->menu->tab_elem[tetris->menu->p_index].id == 2 && !tetris->menu->opt_color)
        tetris->menu->opt_color = true;
    else if (tetris->menu->tab_elem[tetris->menu->p_index].id == 2 && tetris->menu->opt_color)
        tetris->menu->opt_color = false;
    else if (tetris->menu->tab_elem[tetris->menu->p_index].id == 3 && tetris->audio->active_music)
        tetris->audio->active_music = false;
    else if (tetris->menu->tab_elem[tetris->menu->p_index].id == 3 && !tetris->audio->active_music)
        tetris->audio->active_music = true;
    else if (tetris->menu->tab_elem[tetris->menu->p_index].id == 4)
        tetris->state = QUIT;
}

void            menu_logic(t_tetris *tetris)
{
    if (tetris->event == UP && get_timing(tetris, UI))
        up_event(tetris);
    else if (tetris->event == DOWN && get_timing(tetris, UI))
        down_event(tetris);
    else if (tetris->event == ENTER && get_timing(tetris, UI))
        enter_event(tetris);
    else if (tetris->event == ESCAPE && !tetris->menu->opt_color && get_timing(tetris, UI))
    {
        Mix_PlayChannel(-1, tetris->audio->sounds[2], 0);
        if (tetris->audio->active_music)
            Mix_ResumeMusic();
        tetris->menu->p_index = 0;
        set_ref_time_move(tetris);
        set_ref_timer_game(tetris);
        set_ref_time_fall(tetris);
        tetris->state = GAME;
    }
    render_menu(tetris);
}