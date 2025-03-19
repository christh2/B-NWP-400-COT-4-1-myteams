/*
** EPITECH PROJECT, 2024
** cpp project
** File description:
** MyTek 2 project
*/

#include "../../libs/include/server.h"

void print_thread_info(int fd, client_t *client, a_server_t *ftp)
{
    teams_t *team = list_get_elem_by_value(ftp->teams,
    client->user->team, &compare_teams_id);
    chanel_t *canal = list_get_elem_by_value(team->canal,
    client->user->canal, &compare_chanel_id);
    thread_t *thr = list_get_elem_by_value(canal->thread,
    client->user->thread, &compare_thread_id);

    if (!thr || !canal || !team)
        return;
    dprintf(fd, "/lthr:%s:%s:%ld:%s:%s", thr->id,
    thr->creator_id,
    thr->date, thr->name, thr->body);
}

void print_chanel_info(int fd, client_t *client, a_server_t *ftp)
{
    teams_t *team = list_get_elem_by_value(ftp->teams,
    client->user->team, compare_teams_id);
    chanel_t *canal = list_get_elem_by_value(team->canal,
    client->user->canal, &compare_chanel_id);

    if (canal == NULL || !team)
        return;
    dprintf(fd, "/lchan:%s:%s:%s", canal->id,
    canal->name, canal->description);
}

void print_team_info(int fd, client_t *client, a_server_t *ftp)
{
    teams_t *team = list_get_elem_by_value(ftp->teams,
    client->user->team, compare_teams_id);

    if (team == NULL)
        return;
    dprintf(fd, "/lteam:%s:%s:%s", team->id,
    team->name, team->description);
}

void print_user_info(int fd, a_server_t *ftp)
{
    client_t *existing_client = list_get_elem_by_value(ftp->client,
        &fd, &compare_fds);

    if (existing_client == NULL) {
        dprintf(fd, "/blogin");
        return;
    }
    if (strcmp(existing_client->user->name, "") != 0 &&
    strcmp(existing_client->user->id, "") != 0) {
        dprintf(fd, "/user:%s:%s:%d",
        existing_client->user->id,
        existing_client->user->name,
        existing_client->user->status);
    } else {
        dprintf(fd, "/blogin");
        return;
    }
}

void info_command(int fd, client_t *client, a_server_t *ftp)
{
    if (client->user->thread) {
        print_thread_info(fd, client, ftp);
        return;
    }
    if (client->user->canal) {
        print_chanel_info(fd, client, ftp);
        return;
    }
    if (client->user->team) {
        print_team_info(fd, client, ftp);
        return;
    }
    print_user_info(fd, ftp);
}
