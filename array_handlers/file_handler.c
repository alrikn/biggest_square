/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** file_handler
*/

#include "./../include/my.h"
#include <stdbool.h>
#include <stdio.h>

void print_array(char **array, int num_of_line)
{
    for (int i = 0; i < num_of_line; i++) {
        my_cooler_putstr(array[i]);
        my_putstr("\n");
    }
}

int file_handler(char *path)
{
    location_t fm = {0};
    int fd = fs_open_file(path, &fm);
    int num_of_line = num_of_line_giver(fd, &fm);
    int numlen = num_len(num_of_line);
    char **array = NULL;

    len_of_line_giver(fd, numlen, &fm);
    array = twodarray(fd, &fm, numlen);
    if (array == NULL)
        return 84;
    if (correct_format_checker(&fm, array) == false) {
        my_putstr("wrong file format\n");
        return 84;
    }
    array = result_array_giver(array, &fm);
    print_array(array, num_of_line);
    free_array(&fm, array);
    close(fd);
    return 0;
}
