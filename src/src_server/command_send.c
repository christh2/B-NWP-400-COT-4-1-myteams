/*
** EPITECH PROJECT, 2024
** cpp project
** File description:
** MyTek 2 project
*/

#include "../../libs/include/server.h"

void send_message(int fd, char **tab, a_server_t *ftp)
{
    client_t *recup_id;
    msg_t *new_message;
    users_t *existing_client;

    recup_id = list_get_elem_by_value(ftp->client, &fd, &compare_fds);
    existing_client = list_get_elem_by_value(ftp->users, tab[1], compare_uuid);
    if (existing_client == NULL) {
        dprintf(fd, "/bid:%s", tab[1]);
    } else {
        new_message = malloc(sizeof(msg_t));
        strncpy(new_message->body, tab[3], MAX_BODY_LENGTH);
        new_message->body[MAX_BODY_LENGTH - 1] = '\0';
        new_message->sender_id = strdup(recup_id->user->id);
        new_message->receiver_id = strdup(tab[1]);
        new_message->date = time(NULL);
        list_add_elem_at_front(&ftp->messages, new_message);
        dprintf(fd, "/send:%s:%s", tab[1], tab[3]);
        server_event_private_message_sended(recup_id->user->id,
        tab[1], tab[3]);
    }
}

void send_command(int fd, char **tab, a_server_t *ftp)
{
    if (tab[1] == NULL || tab[3] == NULL) {
        dprintf(fd, "Please input a user ID and a message.\n");
        return;
    }
    send_message(fd, tab, ftp);
}
