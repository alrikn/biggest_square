/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** dimension_array
*/

#include "./../include/my.h"
#include <stdio.h>

/*
** if it is a file, the first line should be a bunch of numbers
** telling us how many lines the file has.
*/
int num_of_line_giver(core_t *core)
{
    char buffer[1024] = {0};

    my_strncpy(buffer, core->buffer, 1024);
    my_str_to_int(buffer);
    core->num_of_line = my_str_to_int(buffer);
    return core->num_of_line;
}

/*
** this reade the len of the first line.
** the offset is to skip the metadata (the number of line at top)
** very flimsy, since if there are spaces after the number, everything breaks
*/
int len_of_line_giver(int numlen, core_t *core)
{
    char buf[1024];
    my_strncpy(buf, core->buffer, 1024);
    int temp_len = 0;
    int offset = numlen + 1;

    while (buf[temp_len + offset] != '\n' && buf[temp_len + offset] != '\0') {
        temp_len++;
    }
    core->len_of_line = temp_len;
    return temp_len;
}

/*
** reads every line assuming that there are no bigger lines
** then malloc the array then return it
*/
char **twodarray(core_t *core, int numlen)
{
    char **array = malloc(core->num_of_line * sizeof(char *));
    char buffer[core->len_of_line + 1];
    char *row;

    if (!array)
        return NULL;
    for (int i = 0; i < core->num_of_line; i++) {
        row = core->buffer + numlen + 1 + i * (core->len_of_line + 1);
        my_strncpy(buffer, row, core->len_of_line + 1);
        if (my_strlen(buffer) < core->len_of_line)
            return NULL;
        buffer[core->len_of_line + 1] = '\0';
        array[i] = malloc((core->len_of_line + 1) * sizeof(char));
        if (!array[i])
            return NULL;
        my_strncpy(array[i], buffer, core->len_of_line + 1);
        array[i][core->len_of_line] = '\0';
    }
    return array;
}
