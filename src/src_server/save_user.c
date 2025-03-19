/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/server.h"

void save_user(a_server_t *ftp)
{
    int file;
    users_t *user;

    file = open(".users.wave", O_TRUNC | O_WRONLY);
    while (ftp->users) {
        user = (users_t *)ftp->users->vlue;
        dprintf(file, "%s:%s", user->name, user->id);
        ftp->users = ftp->users->next;
        if (ftp->users)
            dprintf(file, "\n");
    }
    close(file);
}
