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

void list_teams_command(int fd, char **tab, client_t *tmp, a_server_t *ftp)
{
    list_dump(ftp->teams, dump_teams, fd);
}

void list_canal_command(int fd, char **tab, client_t *tmp, a_server_t *ftp)
{
    teams_t *team = list_get_elem_by_value(ftp->teams,
    tmp->user->team, &compare_teams_id);

    list_dump(team->canal, dump_teams, fd);
}

void list_thread_command(int fd, char **tab, client_t *tmp, a_server_t *ftp)
{
    teams_t *team = list_get_elem_by_value(ftp->teams,
    tmp->user->team, &compare_teams_id);
    chanel_t *canal = list_get_elem_by_value(team->canal,
    tmp->user->canal, &compare_chanel_id);

    list_dump(canal->thread, dump_thread, fd);
}

void list_comment_command(int fd, char **tab, client_t *tmp, a_server_t *ftp)
{
    teams_t *team = list_get_elem_by_value(ftp->teams,
    tmp->user->team, &compare_teams_id);
    chanel_t *canal = list_get_elem_by_value(team->canal,
    tmp->user->canal, &compare_chanel_id);
    thread_t *thr = list_get_elem_by_value(canal->thread,
    tmp->user->thread, &compare_thread_id);

    list_dump(thr->comment, dump_comment, fd);
}

void list_command(int fd, char **tab, a_server_t *ftp)
{
    client_t *tmp = list_get_elem_by_value(ftp->client, &fd, &compare_fds);

    if (!tmp->user->team && nb_args(tab) == 1)
        list_teams_command(fd, tab, tmp, ftp);
    if (tmp->user->team && !tmp->user->canal && nb_args(tab) == 1)
        list_canal_command(fd, tab, tmp, ftp);
    if (tmp->user->team && tmp->user->canal && !tmp->user->thread
        && nb_args(tab) == 1)
        list_thread_command(fd, tab, tmp, ftp);
    if (tmp->user->team && tmp->user->canal && tmp->user->thread
        && nb_args(tab) == 1)
        list_comment_command(fd, tab, tmp, ftp);
}
