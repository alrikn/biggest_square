/*
** EPITECH PROJECT, 2024
** bootstrap_setting_up
** File description:
** fs_open_file
*/

#include "./../include/my.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

/*
here we check if file exists and but it into our big buffer
*/
int fs_open_file(char *filepath, core_t *core)
{
    struct stat st;
    int fd = open(filepath, O_RDONLY);
    int correct_read = stat(filepath, &st);

    core->path = filepath;
    if (correct_read == -1 || S_ISDIR(st.st_mode) || st.st_size == 0 || fd < 0) {
        my_cooler_putstr("FAILURE 1\n");
        return 84;
    }
    core->buffer = malloc(sizeof(char) * (st.st_size + 1));
    if (!core->buffer)
        return 84;
    correct_read = read(fd, core->buffer, st.st_size);
    if (correct_read < st.st_size)
        return 84;
    core->buffer[st.st_size] = '\0';
    core->size = st.st_size;
    close(fd);
    return 0;
}
