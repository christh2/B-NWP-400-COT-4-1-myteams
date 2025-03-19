/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/server.h"
#include "../../libs/include/list.h"
#include "../../libs/include/teams.h"
#include "../../libs/include/users.h"
#include "../../libs/include/threads.h"
#include "../../libs/include/canal.h"

void reset_context(client_t *tmp)
{
    if (tmp->user->team)
        free(tmp->user->team);
    if (tmp->user->canal)
        free(tmp->user->canal);
    if (tmp->user->thread)
        free(tmp->user->thread);
    tmp->user->team = NULL;
    tmp->user->canal = NULL;
    tmp->user->thread = NULL;
}

void use_command(int fd, char **tab, a_server_t *ftp)
{
    client_t *tmp = list_get_elem_by_value(ftp->client, &fd, &compare_fds);

    reset_context(tmp);
    if (nb_args(tab) == 2) {
        tmp->user->team = strdup(tab[1]);
    }
    if (nb_args(tab) == 4) {
        tmp->user->team = strdup(tab[1]);
        tmp->user->canal = strdup(tab[3]);
    }
    if (nb_args(tab) == 6) {
        tmp->user->team = strdup(tab[1]);
        tmp->user->canal = strdup(tab[3]);
        tmp->user->thread = strdup(tab[5]);
    }
}
