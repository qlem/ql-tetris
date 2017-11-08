//
// Created by qlem on 14/07/17.
//

#include "../inc/tetris.h"

/*

 ___________________  ________
/_  __/ __/_  __/ _ \/  _/ __/
 / / / _/  / / / , _// /_\ \
/_/ /___/ /_/ /_/|_/___/___/

*/


void        render_start(t_tetris *tetris)
{
    caca_set_color_ansi(tetris->canvas, CACA_LIGHTMAGENTA, CACA_TRANSPARENT);
    caca_put_str(tetris->canvas, 7, 8, " ___________________  ________");
    caca_put_str(tetris->canvas, 7, 9, "/_  __/ __/_  __/ _ \\/  _/ __/");
    caca_put_str(tetris->canvas, 7, 10, " / / / _/  / / / , _// /_\\ \\");
    caca_put_str(tetris->canvas, 7, 11, "/_/ /___/ /_/ /_/|_/___/___/");
    caca_set_color_ansi(tetris->canvas, CACA_DEFAULT, CACA_DEFAULT);
    caca_set_attr(tetris->canvas, CACA_BLINK);
    caca_put_str(tetris->canvas, 13, 20, "Press key to start");
    caca_unset_attr(tetris->canvas, CACA_BLINK);
}
