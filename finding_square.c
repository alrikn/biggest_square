/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** finding_square
*/

#include "./include/my.h"
#include <stdbool.h>

int size_based_on_position(char **array, int x_pos, int y_pos)
{
    int i = 0;
    int j = 0;
    int size_square = 0;
    bool done = false;

    while(done != true) {
        for (int h = 0; j <= i; h++) {
            if (array[i + y_pos][h + x_pos] != '.') {
                done = true;
                break;
            }
        }
        if (done == true) {
            break;
        }
        i++;
    }
    size_square = i;
    return size_square;
}

int biggest_square_finder(char **array, int *final_x_pos, int *final_y_pos, int num_of_line)
{
    int x_pos = 0;
    int y_pos = 0;
    int max_size = 0;
    int temp_max_size = 0;

    while (y_pos != num_of_line) {
        while (array[y_pos][x_pos] != '\0') {
            temp_max_size = size_based_on_position(array, x_pos, y_pos);
            if (temp_max_size > max_size) {
                max_size = temp_max_size;
                //final_x_pos = x_pos;
                //final_y_pos = y_pos;
            }
            x_pos++;
            /*update max_size only if current max_size smaller than
            new max_size and if it is also update the final_x_pos
             and final_y_pos to x_pos and y_pos*/
        }
        y_pos++;
    }
    return max_size;
}

char **result_array_giver(char **array, int num_of_line)
{
    int y_pos = 0;
    int x_pos = 0;
    int j = 0;

    int max_size = biggest_square_finder(array, &x_pos, &y_pos, num_of_line);
    for (int i = 0; i <= max_size; i++) {
        for (int j = 0; j <= max_size; i++) {
            array[i + y_pos][j + x_pos] += 73;
        }
    }
    return array;
}