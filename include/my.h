/*
** EPITECH PROJECT, 2024
** Header Pool Day 5
** File description:
** Header file for the tasks today
*/
#ifndef COMMON_H
    #include <unistd.h>
    #include <limits.h>
    #include <stdlib.h>
    #define COMMON_H
    #define MAX_INT 2147483647
    #define MIN_INT –2147483648
    #include <stdbool.h>
    #include "struct.h"
void my_putchar(char);
int my_putstr(char const *);
int fs_open_file(char *filepath, location_t *fm);
int my_is_digit(char c);
int my_str_to_int(const char *str);
int num_len(int nb);
char **result_array_giver(char **array, location_t *fm);
char *my_strncpy(char *dest, const char *src, unsigned long n);
int num_of_line_giver(int fd, location_t *fm);
int len_of_line_giver(int fd, int numlen, location_t *fm);
char **twodarray(int fd, location_t *fm, int numlen);
int file_handler(char *path);
int my_putstr(char const *str);
int my_strlen(char const *str);
void print_array(char **array, int num_of_line);
void generator_handler(char **argv);
int my_lseek(int fd, unsigned long offset, location_t *fm);
#endif /* COMMON_H */
