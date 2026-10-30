/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** struct
*/

#ifndef INCLUDED_STRUCT_H
    #define INCLUDED_STRUCT_H
#include <stddef.h>

typedef struct square_info {
    int x_pos; //current x position in the array of square
    int y_pos; //current y position in the array of square
    int size;
    int max_size; //max size of square found so far based on position in array
    //max poss size of square based on pos in array & size of array
    int max_possible_size;
} square_info_t;

typedef struct core {
    int len_of_line;
    int num_of_line;
    char *path;
    char *buffer; //the entire file is read into this buffer, so we can avoid multiple system calls
    int valid;
    size_t size; //size of the file, used for malloc
    square_info_t square_info;
} core_t;

#endif
