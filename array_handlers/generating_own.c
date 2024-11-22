/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** generating_own
*/

#include "./../include/my.h"

char **parameters(char **argv, location_t *fm)
{
    char *str_num_of_line = argv[1];
    int num_line = my_str_to_int(str_num_of_line);
    char *normal = argv[2];
    int k = 0;
    char **array = malloc(sizeof(char *) * num_line);

    fm->len_of_line = num_line;
    for (int i = 0; i < num_line; i++) {
        array[i] = malloc(sizeof(char) * (fm->len_of_line + 1));
        for (int j = 0; j < fm->len_of_line; j++) {
            array[i][j] = normal[k % my_strlen(normal)];
            k++;
        }
        array[i][k] = '\0';
    }
    fm->num_of_line = num_line;
    return array;
}

int generator_handler(char **argv)
{
    location_t fm = {0};
    int num_line;
    char **array;

    if (argv[2][0] == '\0')
        return 84;
    array = parameters(argv, &fm);
    if (array == NULL)
        return 84;
    if (correct_format_checker(&fm, array) == false) {
        my_putstr("wrong file format\n");
        return 84;
    }
    num_line = fm.num_of_line;
    array = result_array_giver(array, &fm);
    print_array(array, num_line);
    free_array(&fm, array);
    return 0;
}
