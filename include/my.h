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
int my_cooler_putstr(char const *);
int fs_open_file(char *filepath, core_t *core);
int my_is_digit(char c);
int my_str_to_int(const char *str);
int num_len(int nb);
char **result_array_giver(char **array, core_t *core);
char *my_strncpy(char *dest, const char *src, unsigned long n);
int num_of_line_giver(core_t *core);
int len_of_line_giver(int numlen, core_t *core);
char **twodarray(core_t *core, int numlen);
int file_handler(char *path);
int my_strlen(char const *str);
void print_array(char **array, int num_of_line, core_t *core);
int generator_handler(char **argv);
int my_lseek(int fd, unsigned long offset, core_t *core);
void free_array(core_t *core, char **array);
bool correct_format_checker(core_t *core, char **array);
int my_cooler_putstr(char const *str);
char *my_strncat(char *s1, const char *s2, unsigned long n);
#endif /* COMMON_H */
