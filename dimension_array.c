/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** dimension_array
*/

#include "./include/my.h"
#include "include/struct.h"


int num_of_line_giver(int fd, location_t *fm) {
    char buffer[1024];
    int bytes_read = read(fd, buffer, sizeof(buffer));
    int num_of_line = my_str_to_int(buffer);

    fm->num_of_line = num_of_line;
    if (bytes_read <= 0) {
        exit(84);
        return -1;
    }
    lseek(fd, 0, SEEK_SET);
    return num_of_line;
}

int len_of_line_giver(int fd, int numlen, location_t *fm)
{
    char buf[1024];
    int bytes_read = read(fd, buf, sizeof(buf));
    int temp_len = 0;
    int offset = numlen + 1;

    if (bytes_read <= 0) {
        exit(84);
        return -1;
    }
    while (buf[temp_len + offset] != '\n' && buf[temp_len + offset] != '\0') {
        temp_len++;
    }
    lseek(fd, 0, SEEK_SET);
    fm->len_of_line = temp_len;
    return temp_len;
}

char **twodarray(int fd, int len_of_line, int num_of_line, int numlen)
{
    char **array = malloc(num_of_line * sizeof(char *));
    char buffer[len_of_line + 1];
    int bytes_read = 0;

    if (!array) {
        exit(84);
    }
    lseek(fd, numlen + 1, SEEK_SET);
    for (int i = 0; i < num_of_line; i++) {
        bytes_read = read(fd, buffer, len_of_line + 1);
        if (bytes_read < len_of_line) {
            exit(84);
        }
        buffer[len_of_line + 1] = '\0';
        array[i] = malloc((len_of_line + 1) * sizeof(char));
        if (!array[i]) {
            exit(84);
        }
        my_strncpy(array[i], buffer, len_of_line + 1);
        array[i][len_of_line] = '\0';
    }
    return array;
}
