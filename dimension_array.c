/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** dimension_array
*/

#include "./include/my.h"
#include "include/struct.h"
#include <stdio.h>


int num_of_line_giver(int fd, location_t *fm)
{
    char buffer[1024];
    int bytes_read = read(fd, buffer, sizeof(buffer));
    int num_of_line = my_str_to_int(buffer);

    fm->num_of_line = num_of_line;
    if (bytes_read <= 0) {
        return 0;
    }
    fd = my_lseek(fd, 0, fm);
    return num_of_line;
}

int len_of_line_giver(int fd, int numlen, location_t *fm)
{
    char buf[1024];
    int bytes_read = read(fd, buf, sizeof(buf));
    int temp_len = 0;
    int offset = numlen + 1;

    if (bytes_read <= 0) {
        return 0;
    }
    while (buf[temp_len + offset] != '\n' && buf[temp_len + offset] != '\0') {
        temp_len++;
    }
    fd = my_lseek(fd, 0, fm);
    fm->len_of_line = temp_len;
    return temp_len;
}

char **twodarray(int fd, location_t *fm, int numlen)
{
    char **array = malloc(fm->num_of_line * sizeof(char *));
    char buffer[fm->len_of_line + 1];
    int bytes_read = 0;

    if (!array)
        return NULL;
    fd = my_lseek(fd, numlen + 1, fm);
    for (int i = 0; i < fm->num_of_line; i++) {
        bytes_read = read(fd, buffer, fm->len_of_line + 1);
        if (bytes_read < fm->len_of_line)
            return NULL;
        buffer[fm->len_of_line + 1] = '\0';
        array[i] = malloc((fm->len_of_line + 1) * sizeof(char));
        if (!array[i])
            return NULL;
        my_strncpy(array[i], buffer, fm->len_of_line + 1);
        array[i][fm->len_of_line] = '\0';
    }
    return array;
}
