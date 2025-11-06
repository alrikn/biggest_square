/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** file_handler
*/

#include "./../include/my.h"
#include <stdbool.h>
#include <stdio.h>

/**
 * adding everything to a buffer, with only one system call
 * however, this risks stack overflow
 */
void print_array(char **array, int num_of_line, location_t *fm)
{
    char buffer[(fm->len_of_line + 1) * num_of_line + 1];

    buffer[0] = '\0';
    for (int i = 0; i < num_of_line; i++) {
        my_strncat(buffer, array[i], fm->len_of_line);
        my_strncat(buffer, "\n", 1);
    }
    buffer[(fm->len_of_line + 1) * num_of_line] = '\0';
    my_cooler_putstr(buffer);
}

/*
** we open the file: fs_open_file
** we count how many lines the map has: num_of_line_giver
** we count how many bytes we have to skip: num_len
** (to avoid the first line + the \n)
** looking back at this code, this is a very flimsy way of doing this
** we count the len of the first line: len_of_line_giver
** this is also quite flimsy, as we are just counting the first line
** and assuming every line is the same
** we malloc the array: twodarray
** we check that the map has good characters: correct_format_checker
*/
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
    print_array(array, num_of_line, &fm);
    free_array(&fm, array);
    close(fd);
    return 0;
}
