/*
** EPITECH PROJECT, 2024
** placeholder
** File description:
** Concatinates two strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *str)
{
    char *dest_start = dest;

    while (dest[0] != '\0') {
        dest++;
    }
    while (str[0] != '\0') {
        dest[0] = str[0];
        dest++;
        str++;
    }
    dest = dest_start;
    return dest;
}
