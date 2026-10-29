/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** free_array
*/

#include "./../include/my.h"
#include <stdlib.h>

void free_array(core_t *core, char **array)
{
    for (int i = 0; i < core->num_of_line; i++) {
        free(array[i]);
    }
    free(array);
    free(core->buffer);
}
