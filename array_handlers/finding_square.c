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
static bool is_square_invalid(core_t *core, int row, int column, char **array)
{
    int y = core->square_info.y_pos;
    int x = core->square_info.x_pos;
    int num_l = core->num_of_line;
    int len_l = core->len_of_line;

    return (y + row >= num_l || x + column >= len_l ||
        array[y + row][x + column] != '.');
}

/**
 * checks that all positions in a row is empty (and not out of bounds)
 */
bool is_row_valid(char **array, int row, int size, core_t *core)
{
    for (int column = 0; column < size; column++) {
        if (is_square_invalid(core, row, column, array)) {
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
    for (int row = 0; row < size; row++) {
        if (!is_row_valid(array, row, size, core)) {
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
    int size = core->square_info.max_size;

    while (size < core->square_info.max_possible_size &&
        is_valid_square(array, size + 1, core)) {
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
    int y_pos = core->square_info.y_pos;
    int x_pos = core->square_info.x_pos;
    int temp_size = 0;
    int remaining_width = core->len_of_line - core->square_info.x_pos;
    int remaining_height = core->num_of_line - core->square_info.y_pos;


    if (remaining_width < remaining_height) {
        core->square_info.max_possible_size = remaining_width;
    } else
        core->square_info.max_possible_size = remaining_height;
    if (core->square_info.max_size >= core->square_info.max_possible_size)
        return;
    if (array[y_pos][x_pos] == '.') {
        temp_size = size_based_on_position(array, core);
        if (temp_size > core->square_info.max_size) {
            core->square_info.max_size = temp_size;
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
        core->square_info.y_pos = y_pos;
        if (core->square_info.max_size >= num_line - y_pos)
            break;
        for (int x_pos = 0; x_pos < len_line; x_pos++) {
            core->square_info.x_pos = x_pos;
            max_size_updater(array, core, fxp, fyp);
            max_size = core->square_info.max_size;
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
