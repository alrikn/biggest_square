/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** 2darray
*/

#include "./include/my.h"

/*
the len_of_line_giver is asuming that the file is crrectly formatted and
but it still checks that every line is same size
*/

int len_of_line_giver(int fd, int numlen)
{
    int len_of_line = 0;
    int temp_len = 0;
    int bytes_read = 0;
    char buffer[1024];

    bytes_read = read(fd, buffer, sizeof(buffer));
    while (buffer[temp_len] != '\n' && buffer[temp_len] != '\0') {
        temp_len++;
    }
    len_of_line = temp_len;
    lseek(fd, 0, SEEK_SET);
    return len_of_line;
}

char **twodarray(int fd, int len_of_line, int num_of_line)
{
    char **array = malloc((len_of_line + 1) * num_of_line);
    char buffer[len_of_line + 1];
    int bytes_read = 0;

    for (int i = 0; i < num_of_line; i++) {
        bytes_read = read(fd, buffer, len_of_line);
        buffer[len_of_line] = '\0';
        array[i] = buffer;
        array[i] = malloc((len_of_line +1) * sizeof(char));
        for (int j = 0; j < len_of_line; j++) {
            array[i][j] = buffer[j];
        }
        array[i][len_of_line] = '\0';
    }
    return array;
}
