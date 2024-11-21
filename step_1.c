/*
** EPITECH PROJECT, 2024
** bootstrap_setting_up
** File description:
** fs_open_file
*/

#include "./include/my.h"
#include "include/struct.h"
#include <fcntl.h>
#include <unistd.h>  // For close(), read()

int fs_open_file(char *filepath, location_t *fm)
{
    int fd = 0;

    fd = open(filepath, O_RDONLY);
    fm->path = filepath;
    if (fd == -1) {
        my_putstr("FAILURE 1\n");
        return 84;
    } else {
        return fd;
    }
}
/*
int error_message(char *file_name)
{
    write(1, "cat: ", 5);
    write(1, file_name, my_strlen(file_name));
    write(1, ": No such file or directory\n", 28);
    return 84;
}

void empty_cat(void)
{
    char buffer[2048];
    long bytes_read = 1;

    while (bytes_read > 0) {
        bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));
        write(STDOUT_FILENO, buffer, bytes_read);
    }
}


int copy_cat(int ac, char **av, int i)
{
    long bytes_Read = 1;
    int fd = 0;
    char buffer[31048];

    fd = open(av[i], O_RDONLY);
    if (fd == -1) {
        error_message(av[i]);
        return 84;
    }
    while (bytes_Read > 0) {
        bytes_Read = read(fd, buffer, 31048);
        write(1, buffer, bytes_Read);
    }
    if (bytes_Read == -1) {
        return 0;
    }
    close(fd);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc == 1) {
        empty_cat();
    } else {
        for (int i = 1; i < argc; i++) {
            copy_cat(argc, argv, i);
        }
        return 0;
    }
}
*/

/*
int main(int argc, char **argv)
{
    if (argc == 1) {
        write(1, "FAILURE\n", 8);
    } else {
        for (int i = 1; i < argc; i++) {
            fs_open_file(argv[i]);
        }
        return 0;
    }
}
*/
