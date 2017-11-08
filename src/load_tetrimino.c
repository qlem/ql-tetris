//
// Created by qlem on 15/07/17.
//

#include "../inc/tetris.h"

char    *get_path(char *file)
{
    char    *path;
    char    *dir;
    size_t  size;
    int     i;
    int     j;

    i = -1;
    j = -1;
    dir = "tetrimino/";
    size = strlen(file);
    path = malloc(sizeof(char) * (10 + size + 1));
    if (path == NULL)
        return (NULL);
    while (dir[++i])
        path[i] = dir[i];
    i--;
    while (file[++j])
        path[++i] = file[j];
    path[++i] = 0;
    return (path);
}

char        *read_tetrimino_files(struct dirent *s_dir)
{
    struct stat         info;
    char                *buffer;
    char                *path;
    size_t              size;
    int                 fd;

    path = get_path(s_dir->d_name);
    if ((fd = open(path, O_RDONLY)) == -1)
        return (NULL);
    if (stat(path, &info) == -1)
        return (NULL);
    size = (size_t)info.st_size;
    if ((buffer = malloc(sizeof(char) * size + 1)) == NULL)
        return (NULL);
    memset(buffer, 0, size + 1);
    if (read(fd, buffer, size) == -1)
        return (NULL);
    free(path);
    return (buffer);
}

int     load_tetrimino(t_tetris *tetris)
{
    struct dirent       *s_dir;
    DIR                 *p_dir;
    char                *buffer;

    if ((p_dir = opendir("tetrimino")) == NULL)
    {
        printf("Directory 'tetrimino' not found!\n");
        return (1);
    }
    while ((s_dir = readdir(p_dir)) != NULL)
    {
        if  (strcmp("..", s_dir->d_name) != 0 && strcmp(".", s_dir->d_name) != 0)
        {
            if ((buffer = read_tetrimino_files(s_dir)))
                add_tetrimino(tetris, buffer);
            else
                printf("Error reading file '%s'\n", s_dir->d_name);
        }
    }
    return (0);
}