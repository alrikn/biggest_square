/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** my_strncpy
*/

#include <unistd.h>

char *my_strncpy(char *dest, const char *src, unsigned long n)
{
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}
