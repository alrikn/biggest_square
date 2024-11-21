/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** main
*/

#include "./include/my.h"

int main(int argc, char **argv)
{
    if (argc != 2 && argc != 3) {
        write(1, "FAILURE\n", 8);
        return 84;
    }
    if (argc == 2) {
        file_handler(argv[1]);
    }
    if (argc == 3) {
        generator_handler(argv);
    }
    return 0;
}
