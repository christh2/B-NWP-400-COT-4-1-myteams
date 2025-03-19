/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/server.h"

bool is_directory_exist(char *path)
{
    DIR* dir = opendir(path);

    if (dir) {
        closedir(dir);
        return true;
    } else {
        return false;
    }
}

bool is_digit(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (!is_digit(av[1]))
        return 84;
    multi_server_handler(atoi(av[1]));
    return 0;
}
