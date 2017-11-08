//
// Created by qlem on 18/07/17.
//

#include "../inc/tetris.h"

int     write_new_high_score(long score)
{
    int     fd;
    char    *nbr;
    int     i;

    fd = open("h_score.tetris", O_WRONLY | O_CREAT);
    if (fd == -1)
        return (-1);
    nbr = int_to_str((int)score);
    i = -1;
    while (nbr[++i])
        write(fd, &nbr[i], 1);
    write(fd, "\n", 1);
    close(fd);
    return (0);
}

int     load_high_score(void)
{
    struct stat     info;
    int             fd;
    char            *buffer;
    size_t          size;

    fd = open("h_score.tetris", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd == -1)
        return (0);
    if (stat("h_score.tetris", &info) == -1)
        return (0);
    size = (size_t)info.st_size;
    if (size > 0)
    {
        if ((buffer = malloc(sizeof(char) * size + 1)) == NULL)
            return (0);
        memset(buffer, 0, size + 1);
        if (read(fd, buffer, size) == -1)
            return (0);
        close(fd);
        return(atoi(buffer));
    }
    close(fd);
    return (0);
}