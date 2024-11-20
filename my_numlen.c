/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** my_numlen
*/

int num_len(int nb)
{
    int len = 1;

    if (nb < 0) {
        nb = nb * (-1);
        len++;
    }
    while (nb > 9) {
        nb = nb / 10;
        len++;
    }
    return len;
}
