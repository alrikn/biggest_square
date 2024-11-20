/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** main
*/

#include "./include/my.h"

int main(int argc, char **argv)
{
    if (argc == 1) {
        write(1, "FAILURE\n", 8);
        return 84;
    } else {
        for (int i = 1; i < argc; i++) {
            file_handler(argv[i]);
        }
    }
    return 0;
}
