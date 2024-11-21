/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** my_lseek
*/

#include "./include/my.h"
#include "include/struct.h"
#include <fcntl.h>
#include <stdlib.h>

int my_lseek(int fd, unsigned long offset, location_t *fm)
{
    char *offsetter = malloc(sizeof(char) * (offset + 1));
    char *path = fm->path;

    close(fd);
    fd = open(path, O_RDONLY);
    read(fd, offsetter, offset);
    free(offsetter);
    return fd;
}
