//
// Created by qlem on 14/07/17.
//

#include "../inc/tetris.h"

/*

  _____
 / ___/__  __ _  ___
/ (_ / _ `/  ' \/ -_)
\___/\_,_/_/_/_/\__/
                       ____
                      / __ \_  _____ ____
                     / /_/ / |/ / -_) __/
                     \____/|___/\__/_/

   _  __
  / |/ /__ _    __
 /    / -_) |/|/ /
/_/|_/\__/|__,__/
              __ ___      __
             / // (_)__ _/ /
            / _  / / _ `/ _ \
           /_//_/_/\_, /_//_/
                  /___/
                        ____
                       / __/______  _______
                      _\ \/ __/ _ \/ __/ -_)
                     /___/\__/\___/_/  \__/


*/



void        render_end(t_tetris *tetris)
{
    if (tetris->v_game->score > tetris->v_game->h_score)
    {
        caca_set_color_ansi(tetris->canvas, CACA_GREEN, CACA_TRANSPARENT);
        caca_put_str(tetris->canvas, 1, 1, "   _  __");
        caca_put_str(tetris->canvas, 1, 2, "  / |/ /__ _    __");
        caca_put_str(tetris->canvas, 1, 3, " /    / -_) |/|/ /");
        caca_put_str(tetris->canvas, 1, 4, "/_/|_/\\__/|__,__/");
        caca_put_str(tetris->canvas, 1, 5, "              __ ___      __");
        caca_put_str(tetris->canvas, 1, 6, "             / // (_)__ _/ /");
        caca_put_str(tetris->canvas, 1, 7, "            / _  / / _ `/ _ \\");
        caca_put_str(tetris->canvas, 1, 8, "           /_//_/_/\\_, /_//_/");
        caca_put_str(tetris->canvas, 1, 9, "                  /___/");
        caca_put_str(tetris->canvas, 1, 10, "                        ____");
        caca_put_str(tetris->canvas, 1, 11, "                       / __/______  _______");
        caca_put_str(tetris->canvas, 1, 12, "                      _\\ \\/ __/ _ \\/ __/ -_)");
        caca_put_str(tetris->canvas, 1, 13, "                     /___/\\__/\\___/_/  \\__/");
    }
    else
    {
        caca_set_color_ansi(tetris->canvas, CACA_RED, CACA_TRANSPARENT);
        caca_put_str(tetris->canvas, 1, 2, "  _____");
        caca_put_str(tetris->canvas, 1, 3, " / ___/__  __ _  ___");
        caca_put_str(tetris->canvas, 1, 4, "/ (_ / _ `/  ' \\/ -_)");
        caca_put_str(tetris->canvas, 1, 5, "\\___/\\_,_/_/_/_/\\__/");
        caca_put_str(tetris->canvas, 1, 9, "                       ____");
        caca_put_str(tetris->canvas, 1, 10, "                      / __ \\_  _____ ____");
        caca_put_str(tetris->canvas, 1, 11, "                     / /_/ / |/ / -_) __/");
        caca_put_str(tetris->canvas, 1, 12, "                     \\____/|___/\\__/_/");
    }
    caca_set_color_ansi(tetris->canvas, CACA_DEFAULT, CACA_DEFAULT);
    caca_printf(tetris->canvas, 14, 15, "Your score %6d", tetris->v_game->score);
    caca_set_attr(tetris->canvas, CACA_BLINK);
    caca_put_str(tetris->canvas, 13, 20, "Press R to restart");
    caca_unset_attr(tetris->canvas, CACA_BLINK);
}
