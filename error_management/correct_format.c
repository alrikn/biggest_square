/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** correct_format 6567
*/

#include "./../include/my.h"
#include <stdbool.h>

bool correct_character(core_t *core, char **a, int x, int y)
{
    if (a[y][x] != '\0' && a[y][x] != 'o' && a[y][x] != '.' && a[y][x] != '\n')
        return false;
    return true;
}

bool valid_line(core_t *core, char **array, int y_pos)
{
    for (int x_pos = 0; x_pos < core->len_of_line; x_pos++) {
        if (correct_character(core, array, x_pos, y_pos) == false)
            return false;
    }
    return true;
}

bool correct_format_checker(core_t *core, char **array)
{
    for (int y_pos = 0; y_pos < core->num_of_line; y_pos++) {
        if (valid_line(core, array, y_pos) == false) {
            return false;
        }
    }
    return true;
}
