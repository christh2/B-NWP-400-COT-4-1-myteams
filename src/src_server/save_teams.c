/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/server.h"

void save_comment(teams_t *team, chanel_t *canal, thread_t *thr)
{
    int file;
    comment_t *cmt;

    file = open(".comments.wave", O_APPEND | O_WRONLY);
    while (thr->comment) {
        cmt = (comment_t *)thr->comment->vlue;
        dprintf(file, "%s:%s:%s:%s:%s:%s:%ld", cmt->id, cmt->creator_id,
        team->id, canal->id, thr->id, cmt->body, cmt->date);
        thr->comment = thr->comment->next;
        if (thr->comment)
            dprintf(file, "\n");
    }
    close(file);
}

void save_thr(teams_t *team, chanel_t *canal)
{
    int file;
    thread_t *thr;

    file = open(".threads.wave", O_APPEND | O_WRONLY);
    while (canal->thread) {
        thr = (thread_t *)canal->thread->vlue;
        dprintf(file, "%s:%s:%s:%s:%s:%s:%ld", thr->id, thr->creator_id,
        team->id, canal->id, thr->name, thr->body, thr->date);
        dprintf(file, "hm\n");
        save_comment(team, canal, thr);
        canal->thread = canal->thread->next;
        if (canal->thread)
            dprintf(file, "\n");
    }
    close(file);
}

void save_chanel(teams_t *team)
{
    int file;
    chanel_t *canal;

    file = open(".chanels.wave", O_APPEND | O_WRONLY);
    while (team->canal) {
        canal = (chanel_t *)team->canal->vlue;
        dprintf(file, "%s:%s:%s:%s:%s", canal->id, canal->creator_id,
        team->id, canal->name, canal->description);
        team->canal = team->canal->next;
        if (team->canal)
            dprintf(file, "\n");
        save_thr(team, canal);
    }
    close(file);
}

void save_team_users(a_server_t *ftp, teams_t *team, int file)
{
    users_t *tmp;

    while (team->users) {
        tmp = team->users->vlue;
        dprintf(file, "@%s", tmp->id);
        team->users = team->users->next;
    }
}

void save_teams(a_server_t *ftp)
{
    int file;
    teams_t *team;

    file = open(".teams.wave", O_TRUNC | O_WRONLY);
    close(open(".chanels.wave", O_TRUNC | O_WRONLY));
    close(open(".threads.wave", O_TRUNC | O_WRONLY));
    close(open(".comments.wave", O_TRUNC | O_WRONLY));
    while (ftp->teams) {
        team = (teams_t *)ftp->teams->vlue;
        dprintf(file, "%s:%s:%s:%s", team->id, team->creator_id,
        team->name, team->description);
        ftp->teams = ftp->teams->next;
        save_chanel(team);
        save_team_users(ftp, team, file);
        if (ftp->teams)
            dprintf(file, "\n");
    }
    close(file);
}
