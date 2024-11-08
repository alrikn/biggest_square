/*
** EPITECH PROJECT, 2024
** Day06
** File description:
** task03
*/
#include <unistd.h>
#include "my.h"
char *my_revstr(char *str)
{
    char *endptr = str;
    char *str_start = str;

    while (endptr[1] != '\0') {
        endptr++;
    }
    for (; str_start < endptr; str_start++) {
        my_charswap(str_start, endptr);
        endptr--;
    }
    return str;
}
