/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/server.h"

void load_a_cmt(a_server_t *ftp, char *line)
{
    comment_t *cmt = (comment_t *)malloc(sizeof(thread_t));
    char **tab = fill_it(line, ':');
    teams_t *team = list_get_elem_by_value(ftp->teams,
    tab[2], &compare_teams_id);
    chanel_t *canal = list_get_elem_by_value(team->canal,
    tab[3], &compare_chanel_id);
    thread_t *thr = list_get_elem_by_value(canal->thread,
    tab[4], &compare_thread_id);

    cmt->id = strdup(tab[0]);
    cmt->creator_id = strdup(tab[1]);
    cmt->team_id = strdup(tab[2]);
    cmt->chanel_id = strdup(tab[3]);
    cmt->thread_id = strdup(tab[4]);
    strcpy(cmt->body, tab[5]);
    cmt->date = (time_t)atoi(tab[6]);
    list_add_elem_at_back(&thr->comment, cmt);
    free_tab(tab);
}

void load_comment(a_server_t *ftp)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;

    file = fopen(".comments.wave", "ar+");
    while (getline(&line, &len, file) != -1)
        load_a_cmt(ftp, line);
    fclose(file);
}
