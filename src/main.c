/*
** main.c for foo in /home/qlem/rendu
** 
** Made by qlem
** Login   <clement.dommerc@epitech.eu>
** 
** Started on  Thu Jul 13 03:09:54 2017 qlem
** Last update Fri Jul 14 17:56:27 2017 qlem
*/

#include "../inc/tetris.h"

char    *getHighScoreFilePath(char **env)
{
    int     i;
    int     len;
    char    name[18] = "/.ql_tetris_hscore";
    char    *path;

    i = -1;
    path = NULL;
    while (env[++i] != 0) {
        if (strncmp("HOME=", env[i], 5) == 0) {
            len = (int)strlen(env[i]) - 5;
            path = malloc(sizeof(char) * (len + 19));
            if (path == NULL) {
                return (NULL);
            }
            memcpy(path, &env[i][5], len);
            memcpy(&path[len], name, 18);
            path[len + 19] = 0;
            break;
        }
    }
    return (path);
}

void    init_main_struct(t_tetris *tetris, char *hs_path)
{
    tetris->hs_path = hs_path;
    tetris->state = START;
    tetris->event = NO_PRESSED;
    tetris->menu = malloc_pause_menu();
    tetris->v_game = malloc_var_game();
    tetris->v_game->h_score = load_high_score(hs_path);
    tetris->canvas = caca_create_canvas(WIDTH, HEIGHT);
    tetris->display = caca_create_display(tetris->canvas);
    tetris->timer_core = malloc_timer_core();
}

int     game_loop(t_tetris *tetris)
{
    tetris->v_game->c_tetri = get_tetrimino(tetris);
    tetris->v_game->n_tetri = get_tetrimino(tetris);
    Mix_PlayChannel(-1, tetris->audio->sounds[3], 0);
    // TODO : set delay manually
    caca_set_display_time(tetris->display, 16667);
    set_ref_time_ui(tetris);
    while (tetris->state != QUIT)
    {
        caca_clear_canvas(tetris->canvas);
        set_event(tetris);
        if (tetris->event == CLOSE)
            tetris->state = QUIT;
        if (tetris->state == START)
            start_logic(tetris);
        else if (tetris->state == GAME)
            game_logic(tetris);
        else if (tetris->state == MENU)
            menu_logic(tetris);
        else if (tetris->state == OVER)
            end_logic(tetris);
        caca_refresh_display(tetris->display);
    }
    return (0);
}

int	    main(int argc, char **argv, char **env)
{
    t_tetris      tetris;
    char        *hs_path;

    (void)argc;
    (void)argv;
    srand((unsigned int)time(NULL));
    hs_path = getHighScoreFilePath(env);
    init_main_struct(&tetris, hs_path);
    init_audio(&tetris);
    if (load_tetrimino(&tetris) == 1)
        return (1);
    if (tetris.v_game->nb_tetri == 0) {
        printf("No tetrimino found!\n");
        return (1);
    }
    caca_set_display_title(tetris.display, "Tetris");
    game_loop(&tetris);
    free_mem(&tetris);
    return (0);
}
