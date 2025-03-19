/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/server.h"

void load_subscribed(a_server_t *ftp, list_t **users, char **tab)
{
    users_t *user;

    for (int i = 1; tab[i] != NULL; i++) {
        user = list_get_elem_by_value(ftp->users, tab[i],
        compare_uuid);
        list_add_elem_at_back(users, user);
    }
    free_tab(tab);
}

void load_a_team(a_server_t *ftp, char *line)
{
    teams_t *team = (teams_t *)malloc(sizeof(teams_t));
    char *save = strdup(line);
    char *id = strtok(line, ":");
    char *c_id = strtok(NULL, ":");
    char *name = strtok(NULL, ":");
    char *desc = strtok(NULL, ":@\n");

    team->id = strdup(id);
    team->creator_id = strdup(c_id);
    team->users = NULL;
    team->canal = NULL;
    strcpy(team->name, name);
    strcpy(team->description, desc);
    list_add_elem_at_back(&ftp->teams, team);
    load_subscribed(ftp, &team->users, fill_it(save, '@'));
    free(save);
}

void load_teams(a_server_t *ftp)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;

    file = fopen(".teams.wave", "ar+");
    while (getline(&line, &len, file) != -1)
        load_a_team(ftp, line);
    fclose(file);
}
