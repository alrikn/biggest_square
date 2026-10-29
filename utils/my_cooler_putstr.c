/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** cooler_putstr, thank you big dan for the idea
*/


#include <unistd.h>

static int my_strlen(char const *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }
    return (len);
}

int my_cooler_putstr(char const *str)
{
    int len = my_strlen(str);

    write(1, str, len);
    return (0);
}
