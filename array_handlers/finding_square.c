/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** finding_square
*/

#include "./../include/my.h"
#include <stdbool.h>

static bool correct_square(location_t *fm, int i, int j, char **array)
{
    int y = fm->y_pos;
    int x = fm->x_pos;
    int num_l = fm->num_of_line;
    int len_l = fm->len_of_line;

    if (y + i >= num_l || x + j >= len_l || array[y + i][x + j] != '.') {
        return true;
    } else {
        return false;
    }
}

bool is_row_valid(char **array, int row, int size, location_t *fm)
{
    for (int j = 0; j < size; j++) {
        if (correct_square(fm, row, j, array)) {
            return false;
        }
    }
    return true;
}

bool is_valid_square(char **array, int size, location_t *fm)
{
    for (int i = 0; i < size; i++) {
        if (!is_row_valid(array, i, size, fm)) {
            return false;
        }
    }
    return true;
}

static int size_based_on_position(char **array, location_t *fm)
{
    int size = fm->max_size;

    while (is_valid_square(array, size + 1, fm)) {
        size++;
    }
    return size;
}

static void max_size_updater(char **array, location_t *fm, int *fxp, int *fyp)
{
    int y_pos = fm->y_pos;
    int x_pos = fm->x_pos;
    int temp_size = 0;

    if (array[y_pos][x_pos] == '.') {
        temp_size = size_based_on_position(array, fm);
        if (temp_size > fm->max_size) {
            fm->max_size = temp_size;
            *fxp = x_pos;
            *fyp = y_pos;
        }
    }
}

int biggest_square_finder(char **array, int *fxp, int *fyp, location_t *fm)
{
    int max_size = 0;
    int num_line = fm->num_of_line;
    int len_line = fm->len_of_line;

    for (int y_pos = 0; y_pos < num_line; y_pos++) {
        fm->y_pos = y_pos;
        for (int x_pos = 0; x_pos < len_line; x_pos++) {
            fm->x_pos = x_pos;
            max_size_updater(array, fm, fxp, fyp);
            max_size = fm->max_size;
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
