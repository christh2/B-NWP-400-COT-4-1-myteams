/*
** EPITECH PROJECT, 2024
** cpp project
** File description:
** MyTek 2 project
*/

#include "../../libs/include/server.h"
#include "../../libs/include/message.h"

bool compare_uuid(void *client, void *uuid)
{
    return strcmp(((users_t *)client)->id, (char *)uuid) == 0;
}

void user_command(int fd, char **tab, a_server_t *ftp)
{
    users_t *existing_client;

    if (tab[1] == NULL) {
        dprintf(fd, "/bid:");
        return;
    }
    existing_client = list_get_elem_by_value(ftp->users,
        tab[1], &compare_uuid);
    if (existing_client == NULL) {
        dprintf(fd, "/bid:%s", tab[1]);
    } else {
        dprintf(fd, "/user:%s:%s:%d", existing_client->id,
        existing_client->name, existing_client->status);
    }
}

void messages_command(int fd, char **tab, a_server_t *ftp)
{
    msg_t *message;

    for (size_t i = 0; i < list_get_size(ftp->messages); i++) {
        message = (msg_t *)list_get_elem_at_position(ftp->messages, i);
        if (strcmp(message->sender_id, tab[1]) == 0 ||
            strcmp(message->receiver_id, tab[1]) == 0) {
            dprintf(fd, "/msg:%s:%ld:%s", message->sender_id,
            message->date, message->receiver_id);
            return;
        }
    }
    dprintf(fd, "/bid:%s", tab[1]);
}
