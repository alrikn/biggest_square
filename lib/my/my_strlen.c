/*
** EPITECH PROJECT, 2024
** Day04
** File description:
** Task03
*/
#include "my.h"

int my_strlen(char const *str)
{
    char const *ptr = str;
    int len = 0;

    while (*ptr != '\0') {
        write(1, ptr, 1);
        ptr++;
        len++;
    }
    return (len);
}
