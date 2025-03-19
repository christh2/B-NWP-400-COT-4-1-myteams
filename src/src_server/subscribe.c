/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/server.h"
#include "../../libs/include/list.h"

void subscribe_cmd(int fd, char **tab, a_server_t *ftp)
{
    client_t *tmp = list_get_elem_by_value(ftp->client, &fd, &compare_fds);
    teams_t *the_team;
    int (*func)(char const *, char const *);

    if (!tmp->user || nb_args(tab) != 2)
        return;
    the_team = list_get_elem_by_value(ftp->teams, tab[1], &compare_teams_id);
    if (!the_team || !list_add_elem_at_back(&the_team->users, tmp->user)) {
        dprintf(fd, "/bteam:%s", tab[1]);
        return;
    }
    dprintf(fd, "/sub:%s:%s", tmp->user->id,
    the_team->id);
    server_event_user_subscribed(the_team->id,
    tmp->user->id);
}

void subscribe_info_cmd(int fd, char **tab, a_server_t *ftp)
{
    client_t *tmp = list_get_elem_by_value(ftp->client, &fd, &compare_fds);
    teams_t *the_team;

    if (!tmp->user)
        return;
    the_team = list_get_elem_by_value(ftp->teams, tab[1], &compare_teams_id);
    list_dump(the_team->users, dump_user, fd);
}

void subscribed(int fd, char **tab, a_server_t *ftp)
{
    client_t *tmp = list_get_elem_by_value(ftp->client, &fd, &compare_fds);
    teams_t *tmp1;
    list_t *team = ftp->teams;

    if (!tmp->user)
        return;
    while (team) {
        tmp1 = (teams_t *)team->vlue;
        if (list_get_elem_by_value(tmp1->users, tmp->user->id,
        &compare_uuid) == NULL) {
            team = team->next;
            continue;
        }
        dprintf(fd, "/lteam:%s:%s:%s", tmp1->id,
        tmp1->name, tmp1->description);
        usleep(1000);
        team = team->next;
    }
}

void subscribed_cmd(int fd, char **tab, a_server_t *ftp)
{
    if (nb_args(tab) == 1)
        subscribed(fd, tab, ftp);
    if (nb_args(tab) == 2)
        subscribe_info_cmd(fd, tab, ftp);
}

void unsubscribe_cmd(int fd, char **tab, a_server_t *ftp)
{
    client_t *tmp = list_get_elem_by_value(ftp->client, &fd, &compare_fds);
    teams_t *the_team;
    int (*func)(char const *, char const *);

    if (!tmp->user || nb_args(tab) != 2)
        return;
    the_team = list_get_elem_by_value(ftp->teams, tab[1], &compare_teams_id);
    if (!the_team || !list_del_elem_by_value(&the_team->users,
        tmp->user->id, &compare_uuid)) {
        dprintf(fd, "/bteam:%s", tab[1]);
        return;
    }
    dprintf(fd, "/unsub:%s:%s", tmp->user->id,
    the_team->id);
    server_event_user_unsubscribed(the_team->id,
    tmp->user->id);
}
