/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** file_handler
*/

#include "./include/my.h"
#include <stdio.h>

void print_array(char **array, int num_of_line)
{
    for (int i = 0; i < num_of_line; i++) {
        my_putstr(array[i]);
        my_putstr("\n");
    }
}

int file_handler(char *path)
{
    location_t fm = {0};
    int fd = fs_open_file(path);
    int num_of_line = num_of_line_giver(fd, &fm);
    int numlen = num_len(num_of_line);
    int len_of_line = len_of_line_giver(fd, numlen, &fm);
    char **array = twodarray(fd, len_of_line, num_of_line, numlen);

    array = result_array_giver(array, &fm);
    print_array(array, num_of_line);
    close(fd);
    return 0;
}
