/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/server.h"

void load_a_chanel(a_server_t *ftp, char *line)
{
    chanel_t *canal = (chanel_t *)malloc(sizeof(chanel_t));
    char *id = strtok(line, ":");
    char *c_id = strtok(NULL, ":");
    char *team_id = strtok(NULL, ":");
    char *name = strtok(NULL, ":");
    char *desc = strtok(NULL, ":\n");
    teams_t *team = list_get_elem_by_value(ftp->teams,
    team_id, &compare_teams_id);

    canal->id = strdup(id);
    canal->creator_id = strdup(c_id);
    canal->team_id = strdup(team->id);
    canal->thread = NULL;
    strcpy(canal->name, name);
    strcpy(canal->description, desc);
    list_add_elem_at_back(&team->canal, canal);
}

void load_canals(a_server_t *ftp)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;

    file = fopen(".chanels.wave", "ar+");
    while (getline(&line, &len, file) != -1)
        load_a_chanel(ftp, line);
    fclose(file);
}
