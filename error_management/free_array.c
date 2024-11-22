/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** free_array
*/

#include "./../include/my.h"
#include <stdlib.h>

void free_array(location_t *fm, char **array)
{
    for (int i = 0; i < fm->num_of_line; i++) {
        free(array[i]);
    }
    free(array);
}
