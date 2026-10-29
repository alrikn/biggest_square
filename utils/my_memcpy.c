/*
** EPITECH PROJECT, 2025
** settingup
** File description:
** my_memcpy
*/

#include <stddef.h>

/**
 * copies n bytes from src to dest, regions must not overlap
 * unlike strncpy, it does not stop at '\0' and does not need to look for it
 */
void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *d = dest;
    const char *s = src;

    for (size_t i = 0; i < n; i++)
        d[i] = s[i];
    return dest;
}
