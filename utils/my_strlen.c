/*
** EPITECH PROJECT, 2024
** Day04
** File description:
** Task03
*/
#include <unistd.h>

int my_strlen(char const *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }
    return (len);
}
