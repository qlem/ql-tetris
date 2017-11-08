//
// Created by qlem on 15/07/17.
//

#include "../inc/tetris.h"

void        set_matrix(char *buffer, t_tetrimino *new)
{
    int     y;
    int     x;
    int     i;

    y = 0;
    x = 0;
    i = -1;
    while (buffer[++i])
    {
        if (buffer[i] == '\n')
        {
            y++;
            x = -1;
        }
        else if (buffer[i] == ' ')
            new->matrix[y][x] = -1;
        else
            new->matrix[y][x] = new->color;
        x++;
    }
}

void        set_info(char *buffer, t_tetrimino *new)
{
    char    *width;
    char    *height;
    char    *color;

    width = strtok(buffer, " ");
    height = strtok(NULL, " ");
    color = strtok(NULL, "\0");
    new->width = atoi(width);
    new->height = atoi(height);
    new->color = atoi(color);
}

char        *get_matrix_str(char *buffer)
{
    char    *matrix;
    size_t  size;
    int     i;
    int     j;

    i = -1;
    size = 0;
    while (buffer[++i] && buffer[i] != '\n');
    j = i;
    while (buffer[++i])
        size++;
    matrix = malloc(sizeof(char) * size + 1);
    if (matrix == NULL)
        return (NULL);
    memset(matrix, 0, size + 1);
    i = -1;
    while (buffer[++j])
        matrix[++i] = buffer[j];
    return (matrix);
}

char        *get_info_str(char *buffer)
{
    char    *info;
    size_t  size;
    int     i;

    i = -1;
    size = 0;
    while (buffer[++i] && buffer[i] != '\n')
        size++;
    info = malloc(sizeof(char) * size + 1);
    if (info == NULL)
        return (NULL);
    memset(info, 0, size + 1);
    i = -1;
    while (buffer[++i] && buffer[i] != '\n')
        info[i] = buffer[i];
    return (info);
}

int     set_new_tetrimino(t_tetrimino *new, char *buffer)
{
    int     i;

    i = -1;
    set_info(get_info_str(buffer), new);
    new->matrix = malloc(sizeof(int *) * new->height);
    if (new->matrix == NULL)
        return (-1);
    while (++i < new->height)
    {
        new->matrix[i] = malloc(sizeof(int) * new->width);
        if (new->matrix[i] == NULL)
            return (-1);
    }
    set_matrix(get_matrix_str(buffer), new);
    return (0);
}