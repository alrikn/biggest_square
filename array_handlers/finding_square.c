/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** finding_square
** this is a naive approach, but reasonably fast, and no system calls
** its only redeeming quality is that it is extremely simple to understand
*/

#include "./../include/my.h"
#include <stdbool.h>

/**
 * checks that position is empty (and not out of bounds)
 */
static bool correct_square(core_t *core, int i, int j, char **array)
{
    int y = core->y_pos;
    int x = core->x_pos;
    int num_l = core->num_of_line;
    int len_l = core->len_of_line;

    if (y + i >= num_l || x + j >= len_l || array[y + i][x + j] != '.') {
        return true;
    } else {
        return false;
    }
}

/**
 * checks that all positions in row are empty (and not out of bounds)
 */
bool is_row_valid(char **array, int row, int size, core_t *core)
{
    for (int j = 0; j < size; j++) {
        if (correct_square(core, row, j, array)) {
            return false;
        }
    }
    return true;
}

/**
 * for every row the square would be, we check if all can fit a square
 * if they can't then it wont fit a square, so its invalid
 */
bool is_valid_square(char **array, int size, core_t *core)
{
    for (int i = 0; i < size; i++) {
        if (!is_row_valid(array, i, size, core)) {
            return false;
        }
    }
    return true;
}

/**
 * we return the maximum size of this square.
 * this is done by adding size to it until it is no longer a valid square
 * there is probably a more efficient way of doing this,
 * but this is a very simple approach and easily understandable
 */
static int size_based_on_position(char **array, core_t *core)
{
    int size = core->max_size;

    while (is_valid_square(array, size + 1, core)) {
        size++;
    }
    return size;
}

/**
 * gets called for every position in the square
 * if the position is a . (empty spot),
 * that means we can start checking if the square is big
 */
static void max_size_updater(char **array, core_t *core, int *fxp, int *fyp)
{
    int y_pos = core->y_pos;
    int x_pos = core->x_pos;
    int temp_size = 0;

    if (array[y_pos][x_pos] == '.') {
        temp_size = size_based_on_position(array, core);
        if (temp_size > core->max_size) {
            core->max_size = temp_size;
            *fxp = x_pos;
            *fyp = y_pos;
        }
    }
}

/**
 * loop through all the positions in the array
 */
int biggest_square_finder(char **array, int *fxp, int *fyp, core_t *core)
{
    int max_size = 0;
    int num_line = core->num_of_line;
    int len_line = core->len_of_line;

    for (int y_pos = 0; y_pos < num_line; y_pos++) {
        core->y_pos = y_pos;
        for (int x_pos = 0; x_pos < len_line; x_pos++) {
            core->x_pos = x_pos;
            max_size_updater(array, core, fxp, fyp);
            max_size = core->max_size;
        }
    }
    return max_size;
}

/**
 * changes the already malloced array to host the biggest square
 * (replaces . with x at right position)
 */
void mark_largest_square(char **array, int x_pos, int y_pos, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            array[y_pos + i][x_pos + j] = 'x';
        }
    }
}

/**
 * this file returns the result array that has the big square
 * does this by getting the size, and the top left position
 * of the biggest square
 */
char **result_array_giver(char **array, core_t *core)
{
    int x_pos = 0;
    int y_pos = 0;
    int max_size = biggest_square_finder(array, &x_pos, &y_pos, core);

    mark_largest_square(array, x_pos, y_pos, max_size);
    return array;
}
