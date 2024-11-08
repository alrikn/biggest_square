/*
** EPITECH PROJECT, 2024
** day06
** File description:
** replacing string for another
*/

#include <unistd.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n || *dest == '\0') {
        if (*src != '\0') {
            *dest = *src;
            src++;
        }
        i++;
        dest++;
    }
    if (i == n) {
        *dest = '\0';
    }
    return (dest);
}
