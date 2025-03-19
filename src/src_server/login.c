/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/server.h"
#include "../../libs/include/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <uuid/uuid.h>
#include "../../libs/include/teams.h"
#include "../../libs/include/users.h"
#include "../../libs/include/threads.h"
#include "../../libs/include/canal.h"

void logout_command(int fd, a_server_t *server)
{
    client_t *tmp = list_get_elem_by_value(server->client, &fd, &compare_fds);
    users_t *user;
    list_t *l_tmp;
    int (*func)(char const *user_uuid);

    if (!tmp->user)
        return;
    user = list_get_elem_by_value(server->users,
    tmp->user->id, compare_uuid);
    server_event_user_logged_out(user->id);
    if (user != NULL) {
        dprintf(fd, "/logout:%s:%s", user->id, user->name);
        list_del_elem_by_value(&server->client, &fd, &compare_fds);
        user->status = get_status(server->client, user->id);
    }
    if (user->status == 0)
        logout_print(user, server);
    close(fd);
    FD_CLR(fd, &server->sets.my_fds);
}

void init_user(char *str, char *new_id, users_t *new_client)
{
    if (str != NULL)
        strncpy(new_client->name, str, MAX_NAME_LENGTH - 1);
    else
        new_client->name[0] = '\0';
    new_client->id = new_id;
    new_client->status = 1;
    new_client->team = NULL;
    new_client->canal = NULL;
    new_client->thread = NULL;
}

void create_a_user(int fd, char *str, a_server_t *ftp)
{
    client_t *tmp = list_get_elem_by_value(ftp->client, &fd, &compare_fds);
    int (*func)(char const *user_uuid, char const *user_name);
    int (*func2)(char const *user_uuid);
    char *new_id;
    list_t *l_tmp;
    users_t *new_client;

    new_id = generate_uuid();
    new_client = (users_t *)malloc(sizeof(users_t));
    init_user(str, new_id, new_client);
    list_add_elem_at_back(&ftp->users, new_client);
    tmp->user = new_client;
    server_event_user_created(new_client->id, new_client->name);
    server_event_user_logged_in(new_client->id);
    for (l_tmp = ftp->client; l_tmp != NULL; l_tmp = l_tmp->next) {
        tmp = (client_t *)l_tmp->vlue;
        dprintf(tmp->fd, "/login:%s:%s", new_client->id, new_client->name);
    }
}

void logged_a_user(int fd, users_t *existing_client, a_server_t *ftp)
{
    client_t *tmp = list_get_elem_by_value(ftp->client, &fd, &compare_fds);
    int (*func)(char const *user_uuid);

    server_event_user_logged_in(existing_client->id);
    dprintf(fd, "/login:%s:%s",
    existing_client->id, existing_client->name);
    existing_client->status = 1;
    tmp->user = existing_client;
}

void login_command(int fd, char **tab, a_server_t *ftp)
{
    users_t *existing_client;

    if (nb_args(tab) == 1) {
        dprintf(fd, "/blogin");
        return;
    }
    existing_client = list_get_elem_by_value(ftp->users,
        tab[1], &compare_username);
    if (!existing_client)
        create_a_user(fd, tab[1], ftp);
    else
        logged_a_user(fd, existing_client, ftp);
}
