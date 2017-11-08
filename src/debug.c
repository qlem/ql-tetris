//
// Created by qlem on 14/07/17.
//

#include "../inc/tetris.h"

void    display_matrix(t_tetrimino *tetrimino)
{
    int     i;
    int     j;

    i = -1;
    while (++i < tetrimino->height)
    {
        j = -1;
        while (++j < tetrimino->width)
        {
            if (tetrimino->matrix[i][j] != -1)
                write(1, "o", 1);
            else
                write(1, " ", 1);
        }
        write(1, "\n", 1);
    }
}