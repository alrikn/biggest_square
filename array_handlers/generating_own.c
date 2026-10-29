/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** generating_own
*/

#include "./../include/my.h"

/**
 * this func is for when we generate the map based of cl parameters
 * argv[1] is the number of lines
 * argv[2] is the string that will be used
 *
 * the way it does this is that it simply concatenates the str and copies
 * it over and over in the lines
 * final result is a square array,
 * that holds the str repeated over and over again
 */
char **parameters(char **argv, core_t *core)
{
    char *str_num_of_line = argv[1];
    int num_line = my_str_to_int(str_num_of_line);
    char *normal = argv[2];
    int k = 0;
    char **array = malloc(sizeof(char *) * num_line);

    core->len_of_line = num_line;
    for (int i = 0; i < num_line; i++) {
        array[i] = malloc(sizeof(char) * (core->len_of_line + 1));
        for (int j = 0; j < core->len_of_line; j++) {
            array[i][j] = normal[k % my_strlen(normal)];
            k++;
        }
        array[i][core->len_of_line] = '\0';
    }
    core->num_of_line = num_line;
    return array;
}

/*
generates the file, than checks it and solves it
*/
int generator_handler(char **argv)
{
    core_t core = {0};
    int num_line;
    char **array;

    if (argv[2][0] == '\0')
        return 84;
    array = parameters(argv, &core);
    if (array == NULL)
        return 84;
    if (correct_format_checker(&core, array) == false) {
        my_cooler_putstr("wrong file format\n");
        return 84;
    }
    num_line = core.num_of_line;
    array = result_array_giver(array, &core);
    print_array(array, num_line, &core);
    free_array(&core, array);
    return 0;
}
