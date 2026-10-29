/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** struct
*/

#ifndef INCLUDED_STRUCT_H
    #define INCLUDED_STRUCT_H
typedef struct core {
    int len_of_line;
    int num_of_line;
    int x_pos;
    int y_pos;
    int max_size;
    char *path;
    char *buffer; //the entire file is read into this buffer, so we can avoid multiple system calls
    int valid;
} core_t;

#endif
