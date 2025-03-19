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

void create_team_event(int fd, teams_t *team, a_server_t *ftp)
{
    list_t *tmp = ftp->client;
    client_t *tmp2;

    while (tmp) {
        tmp2 = (client_t *)tmp->vlue;
        dprintf(tmp2->fd, "/e_cre_team:%s:%s:%s", team->id,
        team->name, team->description);
        tmp = tmp->next;
    }
}

void create_chanel_event(int fd, teams_t *team,
    chanel_t *canal, a_server_t *ftp)
{
    list_t *tmp = ftp->client;
    client_t *tmp2;

    while (tmp) {
        tmp2 = (client_t *)tmp->vlue;
        if (!tmp2->user) {
            tmp = tmp->next;
            continue;
        }
        if (list_get_elem_by_value(team->users,
        tmp2->user->id, compare_uuid) == NULL) {
            tmp = tmp->next;
            continue;
        }
        dprintf(tmp2->fd, "/e_cre_chan:%s:%s:%s", canal->id,
        canal->name, canal->description);
        tmp = tmp->next;
    }
}

void create_thr_event(int fd, teams_t *team, thread_t *thr, a_server_t *ftp)
{
    list_t *tmp = ftp->client;
    client_t *tmp2;
    client_t *tmp3 = list_get_elem_by_value(ftp->client, &fd, &compare_fds);

    dprintf(fd, "/cre_thr:%s:%s:%ld:%s:%s", thr->id, tmp3->user->id,
    thr->date, thr->name, thr->body);
    usleep(1000);
    while (tmp) {
        tmp2 = (client_t *)tmp->vlue;
        if (!tmp2->user || !list_get_elem_by_value(team->users,
        tmp2->user->id, compare_uuid)) {
            tmp = tmp->next;
            continue;
        }
        dprintf(tmp2->fd, "/e_cre_thr:%s:%s:%ld:%s:%s",
        thr->id, tmp3->user->id,
        thr->date, thr->name, thr->body);
        tmp = tmp->next;
    }
}

void create_cmt_event(int fd, teams_t *team, comment_t *cmt, a_server_t *ftp)
{
    list_t *tmp = ftp->client;
    client_t *tmp2;
    client_t *tmp3 = list_get_elem_by_value(ftp->client, &fd, &compare_fds);

    dprintf(fd, "/cre_cmt:%s:%s:%ld:%s", cmt->id, tmp3->user->id,
    cmt->date, cmt->body);
    usleep(1000);
    while (tmp) {
        tmp2 = (client_t *)tmp->vlue;
        if (!tmp2->user || !list_get_elem_by_value(team->users,
        tmp2->user->id, compare_uuid)) {
            tmp = tmp->next;
            continue;
        }
        dprintf(tmp2->fd, "/e_cre_cmt:%s:%s:%ld:%s", team->id, tmp3->user->id,
        cmt->thread_id, cmt->body);
        tmp = tmp->next;
    }
}
