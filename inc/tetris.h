/*
** tetris.h for tetris in /home/qlem/rendu/tetris/inc
** 
** Made by qlem
** Login   <clement.dommerc@epitech.eu>
** 
** Started on  Fri Jul 14 17:54:48 2017 qlem
** Last update Fri Jul 14 17:55:56 2017 qlem
*/

#ifndef _TETRIS_H_
# define _TETRIS_H_

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "caca/caca.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include "int_to_str.h"

#define WIDTH 45
#define HEIGHT 22

#define GRID_W 10
#define GRID_H 20

#define BILLION 1000000000

#define NB_SAMPLES 5

/*
** ENUM
*/

// Events
typedef enum    e_event
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    ESCAPE,
    ENTER,
    RESTART,
    KEY_PRESSED,
    NO_PRESSED,
    CLOSE
}               e_event;

// States game
typedef enum    e_state
{
    START,
    GAME,
    MENU,
    OVER,
    QUIT
}               e_state;

// Timing type
typedef enum    e_timer_t
{
    FALL,
    MOVE,
    UI
}               e_timer_t;

/*
** STRUCTURES
*/

// Tetrimino
typedef struct          s_position
{
    int                 s_x;
    int                 e_x;
    int                 s_y;
    int                 e_y;
}                       t_position;

typedef struct              s_tetrimino
{
    int                     width;
    int                     height;
    int                     color;
    int                     **matrix;
    t_position              position;
    struct s_tetrimino      *next;
}                           t_tetrimino;

// Menu
typedef struct      s_color
{
    char            *name;
    int             color;
}                   t_color;

typedef struct      s_subm_color
{
    t_color         tab_color[7];
    int             p_index;
    int             nb_color;
}                   t_subm_color;

typedef struct      s_elem
{
    char            *name;
    int             id;
}                   t_elem;

typedef struct      s_menu
{
    t_elem          tab_elem[5];
    t_subm_color    *subm_color;
    int             nb_elem;
    int             p_index;
    bool            opt_color;
}                   t_menu;

// Timer game
typedef struct      s_timer_game
{
    time_t          sec;
    time_t          min;
    time_t          hour;
    time_t          ref;
}                   t_timer_game;

// Vars game
typedef struct      s_v_game
{
    long            score;
    long            h_score;
    int             level;
    int             nb_lines;
    int             nb_tetri;
    int             **grid;
    t_timer_game    *timer_game;
    t_tetrimino     *l_tetri;
    t_tetrimino     *n_tetri;
    t_tetrimino     *c_tetri;
}                   t_v_game;

// Audio
typedef struct          s_audio
{
    Mix_Chunk           *sounds[NB_SAMPLES];
    Mix_Music           *music;
    bool                active_music;
}                       t_audio;

// Timer core
typedef struct          s_timer_core
{
    double              ref_time_fall;
    double              ref_time_move;
    double              ref_time_ui;
}                       t_timer_core;

// Main structure
typedef struct          s_tetris
{
    e_state             state;
    e_event             event;
    t_menu              *menu;
    t_v_game            *v_game;
    caca_display_t      *display;
    caca_canvas_t       *canvas;
    t_audio             *audio;
    t_timer_core        *timer_core;
}                       t_tetris;

/*
** FUNCTIONS
*/

// Debug
void            display_matrix(t_tetrimino *tetrimino);

// Free
int             free_matrix(t_tetrimino *tetrimino);
int             free_mem(t_tetris *tetris);

// Load Tetrimino
int             set_new_tetrimino(t_tetrimino *new, char *buffer);
void            add_tetrimino(t_tetris *tetris, char *buffer);
int             load_tetrimino(t_tetris *tetris);

// Vars game
t_menu          *malloc_pause_menu(void);
t_v_game        *malloc_var_game(void);

// Load and write high score
int             write_new_high_score(long score);
int             load_high_score(void);

// Timer game
void            update_timer_game(t_tetris *tetris);
void            set_ref_timer_game(t_tetris *tetris);
t_timer_game    *malloc_timer_game(void);

// Audio
void            free_audio(t_tetris *tetris);
int             init_audio(t_tetris *tetris);

// Timer core
bool            get_timing(t_tetris *tetris, e_timer_t timer_type);
void            set_ref_time_fall(t_tetris *tetris);
void            set_ref_time_ui(t_tetris *tetris);
void            set_ref_time_move(t_tetris *tetris);
t_timer_core    *malloc_timer_core(void);

// Render
enum caca_color get_color(int color);
void            render_menu(t_tetris *tetris);
void            render_end(t_tetris *tetris);
void            render_start(t_tetris *tetris);
void            render_grid(t_tetris *tetris);
void            render_game(t_tetris *tetris);

// Move - rotation
bool            move_down(t_tetris *tetris);
bool            move_left(t_tetris *tetris);
bool            move_right(t_tetris *tetris);
bool            rotate(t_tetris *tetris);
bool            check_rotate(t_tetris *tetris);

// Logic
void            restart_game(t_tetris *tetris);
t_tetrimino     *get_tetrimino(t_tetris *tetris);
void            menu_logic(t_tetris *tetris);
void            end_logic(t_tetris *tetris);
void            start_logic(t_tetris *tetris);
void            game_logic(t_tetris *tetris);
void            set_event(t_tetris *tetris);


#endif /* !TERIS_H_ */
