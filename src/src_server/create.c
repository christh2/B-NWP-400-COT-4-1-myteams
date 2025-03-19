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

void create_teams_command(int fd, char **tab, client_t *tmp, a_server_t *ftp)
{
    teams_t *team;
    int (*func)(char const *,
    char const *, char const *);

    team = list_get_elem_by_value(ftp->teams, tab[1],
    compare_teams_name);
    if (team)
        return (void)dprintf(fd, "/already");
    team = init_team(tmp->user->id);
    strcpy(team->name, tab[1]);
    strcpy(team->description, tab[3]);
    list_add_elem_at_back(&team->users, tmp->user);
    list_add_elem_at_back(&ftp->teams, team);
    server_event_team_created(team->id,
    team->name, tmp->user->id);
    dprintf(fd, "/cre_team:%s:%s:%s", team->id,
    team->name, team->description);
    usleep(1000);
    create_team_event(fd, team, ftp);
}

void create_canal_command(int fd, char **tab, client_t *tmp, a_server_t *ftp)
{
    teams_t *team = list_get_elem_by_value(ftp->teams,
    tmp->user->team, &compare_teams_id);
    chanel_t *canal = list_get_elem_by_value(team->canal,
    tab[1], &compare_chanel_id);
    int (*func)(char const *,
    char const *, char const *);

    if (!team || canal)
        return (void)dprintf(fd, "/already");
    canal = init_canal(tmp->user->id, team);
    strcpy(canal->name, tab[1]);
    strcpy(canal->description, tab[3]);
    list_add_elem_at_back(&team->canal, canal);
    dprintf(fd, "/cre_chan:%s:%s:%s", canal->id, canal->name,
    canal->description);
    usleep(1000);
    create_chanel_event(fd, team, canal, ftp);
    server_event_channel_created(team->id,
    canal->id, canal->name);
}

void create_thread_command(int fd, char **tab, client_t *tmp, a_server_t *ftp)
{
    teams_t *team = list_get_elem_by_value(ftp->teams,
    tmp->user->team, &compare_teams_id);
    chanel_t *canal = list_get_elem_by_value(team->canal,
    tmp->user->canal, &compare_chanel_id);
    thread_t *thr = list_get_elem_by_value(canal->thread,
    tmp->user->thread, &compare_thread_id);
    int (*func) (char const *, char const *,
    char const *, char const *, char const *);

    if (thr || !team || !canal)
        return (void)dprintf(fd, "/already");
    thr = init_thread(tmp->user->id, team, canal);
    strcpy(thr->name, tab[1]);
    strcpy(thr->body, tab[3]);
    list_add_elem_at_back(&canal->thread, thr);
    create_thr_event(fd, team, thr, ftp);
    server_event_thread_created(canal->id,
    thr->id, tmp->user->id, thr->name, thr->body);
}

void create_comment_command(int fd, char **tab, client_t *tmp, a_server_t *ftp)
{
    comment_t *cmt;
    teams_t *team = list_get_elem_by_value(ftp->teams,
    tmp->user->team, &compare_teams_id);
    chanel_t *canal = list_get_elem_by_value(team->canal,
    tmp->user->canal, &compare_chanel_id);
    thread_t *thr = list_get_elem_by_value(canal->thread,
    tmp->user->thread, &compare_thread_id);
    int (*func) (char const *, char const *,
    char const *, char const *);

    if (!team || !canal || !thr || !func)
        return (void)dprintf(fd, "/bteam:%s", tmp->user->team);
    cmt = init_cmt(tmp->user->id, team, canal, thr);
    strcpy(cmt->body, tab[1]);
    list_add_elem_at_back(&thr->comment, cmt);
    client_event_thread_reply_received(team->id,
    thr->id, tmp->user->id, thr->body);
    create_cmt_event(fd, team, cmt, ftp);
}

void create_command(int fd, char **tab, a_server_t *ftp)
{
    client_t *tmp = list_get_elem_by_value(ftp->client, &fd, &compare_fds);

    if (!tmp->user->team && nb_args(tab) == 4)
        create_teams_command(fd, tab, tmp, ftp);
    if (tmp->user->team && !tmp->user->canal && nb_args(tab) == 4)
        create_canal_command(fd, tab, tmp, ftp);
    if (tmp->user->team && tmp->user->canal && !tmp->user->thread
        && nb_args(tab) == 4)
        create_thread_command(fd, tab, tmp, ftp);
    if (tmp->user->team && tmp->user->canal && tmp->user->thread
        && nb_args(tab) == 2)
        create_comment_command(fd, tab, tmp, ftp);
}
