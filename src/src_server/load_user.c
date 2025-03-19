/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/server.h"

void load_user(a_server_t *ftp, FILE *file)
{
    char *line = NULL;
    size_t len = 0;
    char *name;
    char *id;
    users_t *new_client;

    file = fopen(".users.wave", "ar+");
    while (getline(&line, &len, file) != -1) {
        new_client = (users_t *)malloc(sizeof(users_t));
        name = strtok(line, ":");
        id = strtok(NULL, ":\n");
        if (!id || !name)
            continue;
        new_client->id = strdup(id);
        strcpy(new_client->name, name);
        server_event_user_loaded(new_client->id, new_client->name);
        list_add_elem_at_back(&ftp->users, new_client);
    }
    fclose(file);
}

void load_data(a_server_t *ftp)
{
    FILE *file;

    load_user(ftp, file);
    load_teams(ftp);
    load_canals(ftp);
    load_thread(ftp);
    load_comment(ftp);
}
