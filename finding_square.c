/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** finding_square
*/

#include "./include/my.h"
#include "include/struct.h"
#include <stdbool.h>



bool is_valid_square(char **array, int size, location_t *fm)
{
    int y_pos = fm->y_pos;
    int x_pos = fm->x_pos;
    int num_line = fm->num_of_line;
    int len_line = fm->len_of_line;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (y_pos + i >= num_line || x_pos + j >= len_line || array[y_pos + i][x_pos + j] != '.') {
                return false;
            }
        }
    }
    return true;
}

int size_based_on_position(char **array, location_t *fm)
{
    int size = 0;

    while (is_valid_square(array, size + 1, fm)) {
        size++;
    }
    return size;
}

int biggest_square_finder(char **array, int *final_x_pos, int *final_y_pos, location_t *fm)
{
    int max_size = 0;
    int temp_size = 0;
    int num_line = fm->num_of_line;
    int len_line = fm->len_of_line;

    for (int y_pos = 0; y_pos < num_line; y_pos++) {
        fm->y_pos = y_pos;
        for (int x_pos = 0; x_pos < len_line; x_pos++) {
            fm->x_pos = x_pos;
            if (array[y_pos][x_pos] == '.') {
                temp_size = size_based_on_position(array, fm);
                if (temp_size > max_size) {
                    max_size = temp_size;
                    *final_x_pos = x_pos;
                    *final_y_pos = y_pos;
                }
            }
        }
    }
    return max_size;
}

void mark_largest_square(char **array, int x_pos, int y_pos, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            array[y_pos + i][x_pos + j] = 'x';
        }
    }
}

char **result_array_giver(char **array, location_t *fm)
{
    int x_pos = 0;
    int y_pos = 0;
    int max_size = biggest_square_finder(array, &x_pos, &y_pos, fm);

    mark_largest_square(array, x_pos, y_pos, max_size);
    return array;
}
