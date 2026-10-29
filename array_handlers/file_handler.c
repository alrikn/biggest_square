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
 * adding everything to a buffer, with only 2 system call
 */
void print_array(char **array, int num_of_line, core_t *core)
{
    char *buffer = malloc((core->len_of_line + 1) * num_of_line + 1);

    buffer[0] = '\0';
    for (int i = 0; i < num_of_line; i++) {
        my_strncat(buffer, array[i], core->len_of_line);
        my_strncat(buffer, "\n", 1);
    }
    buffer[(core->len_of_line + 1) * num_of_line] = '\0';
    my_cooler_putstr(buffer);
    free(buffer);
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
    core_t core = {0};
    int valid_file = fs_open_file(path, &core);
    char **array = NULL;

    if (valid_file != 0)
        return 84;
    num_of_line_giver(&core);
    len_of_line_giver(num_len(core.num_of_line), &core);
    array = twodarray(&core, num_len(core.num_of_line));
    if (array == NULL)
        return 84;
    if (correct_format_checker(&core, array) == false) {
        my_cooler_putstr("wrong file format\n");
        return 84;
    }
    array = result_array_giver(array, &core);
    print_array(array, core.num_of_line, &core);
    free_array(&core, array);
    return 0;
}
