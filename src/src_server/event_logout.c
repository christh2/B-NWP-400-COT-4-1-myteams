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

void logout_print(users_t *user, a_server_t *server)
{
    list_t *l_tmp;
    client_t *tmp;

    for (l_tmp = server->client; l_tmp != NULL; l_tmp = l_tmp->next) {
        tmp = (client_t *)l_tmp->vlue;
        dprintf(tmp->fd, "/logout:%s:%s", user->id, user->name);
    }
}
