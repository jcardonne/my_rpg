/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** random
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int get_random_seed(void)
{
    int fd = open("/dev/random", O_RDONLY);
    if (fd == -1)
        return 0;
    char buffer[10];
    if (read(fd, buffer, 10) == -1)
        return 0;
    int seed = 0;
    for (int i = 0; i < 10; ++i)
        seed += buffer[i];
    close(fd);
    return seed;
}
