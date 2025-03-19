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

teams_t *init_team(char *id)
{
    teams_t *team = (teams_t *)malloc(sizeof(teams_t));

    team->id = generate_uuid();
    team->creator_id = strdup(id);
    team->users = NULL;
    team->canal = NULL;
    return team;
}

chanel_t *init_canal(char *id, teams_t *team)
{
    chanel_t *canal = (chanel_t *)malloc(sizeof(chanel_t));

    canal->id = generate_uuid();
    canal->creator_id = strdup(id);
    canal->team_id = strdup(team->id);
    canal->thread = NULL;
    return canal;
}

thread_t *init_thread(char *id, teams_t *team, chanel_t *canal)
{
    thread_t *thr = (thread_t *)malloc(sizeof(thread_t));

    thr->id = generate_uuid();
    thr->creator_id = strdup(id);
    thr->team_id = strdup(team->id);
    thr->chanel_id = strdup(canal->id);
    thr->comment = NULL;
    thr->date = time(NULL);
    return thr;
}

comment_t *init_cmt(char *id, teams_t *team, chanel_t *canal, thread_t *thr)
{
    comment_t *cmt = (comment_t *)malloc(sizeof(comment_t));

    cmt->id = generate_uuid();
    cmt->creator_id = strdup(id);
    cmt->team_id = strdup(team->id);
    cmt->chanel_id = strdup(canal->id);
    cmt->thread_id = strdup(thr->id);
    cmt->date = time(NULL);
    return cmt;
}
