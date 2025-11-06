/*
** EPITECH PROJECT, 2025
** settingup
** File description:
** my_strncat
*/

#include <string.h>

static int my_static_strlen(char const *str)
{
    char const *ptr = str;
    int len = 0;

    while (*ptr != '\0') {
        ptr++;
        len++;
    }
    return (len);
}

static char *my_static_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    if (i < n)
        dest[i] = '\0';
    return dest;
}

/**
 * based of of the original strncat
 */
char *my_strncat(char *s1, const char *s2, unsigned long n)
{
    char *s = s1;

    s1 += my_static_strlen(s1);
    my_static_strncpy(s1, s2, n);
    s1[n] = '\0';
    return s;
}
