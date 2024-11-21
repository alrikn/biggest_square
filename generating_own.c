/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** generating_own
*/

#include "./include/my.h"
#include "include/struct.h"

char **parameters(char **argv, location_t *fm)
{
    char *str_num_of_line = argv[1];
    int num_line = my_str_to_int(str_num_of_line);
    char *normal = argv[2];
    int k = 0;
    int around_the_world;
    char **array = malloc(sizeof(char *) * num_line);

    fm->len_of_line = (my_strlen(normal));
    for (int i = 0; i < num_line; i++) {
        k = 0;
        array[i] = malloc(sizeof(char) * fm->len_of_line + 1);
        for (int j = 0; j < fm->len_of_line; j++) {
            around_the_world = (i + j) % fm->len_of_line;
            array[i][k] = normal[around_the_world];
            k++;
        }
        array[i][k] = '\0';
    }
    fm->num_of_line = num_line;
    return array;
}

void generator_handler(char **argv)
{
    location_t fm = {0};
    int num_line;
    char **array = parameters(argv, &fm);

    num_line = fm.num_of_line;
    array = result_array_giver(array, &fm);
    print_array(array, num_line);
    free_array(&fm, array);
}
