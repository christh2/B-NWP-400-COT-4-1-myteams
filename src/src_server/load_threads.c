/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/server.h"

void load_a_thr(a_server_t *ftp, char *line)
{
    thread_t *thr = (thread_t *)malloc(sizeof(thread_t));
    char **tab = fill_it(line, ':');
    teams_t *team = list_get_elem_by_value(ftp->teams,
    tab[2], &compare_teams_id);
    chanel_t *canal = list_get_elem_by_value(team->canal,
    tab[3], &compare_chanel_id);

    thr->id = strdup(tab[0]);
    thr->creator_id = strdup(tab[1]);
    thr->team_id = strdup(tab[2]);
    thr->chanel_id = strdup(tab[3]);
    thr->comment = NULL;
    strcpy(thr->name, tab[4]);
    strcpy(thr->body, tab[5]);
    thr->date = (time_t)atoi(tab[6]);
    list_add_elem_at_back(&canal->thread, thr);
    free_tab(tab);
}

void load_thread(a_server_t *ftp)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;

    file = fopen(".threads.wave", "ar+");
    while (getline(&line, &len, file) != -1)
        load_a_thr(ftp, line);
    fclose(file);
}
