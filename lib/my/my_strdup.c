/*
** EPITECH PROJECT, 2024
** day08 task1
** File description:
** duplicator
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int n = 0;
    int len = my_strlen(src);
    char *dest = malloc(len + 1);

    if (dest == NULL) {
        return NULL;
    }
    for (n = 0; n < len; n++) {
        dest[n] = src[n];
    }
    dest[len] = 0;
    return dest;
}
