/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/server.h"
#include "../../libs/include/list.h"

void dump_user(void *t1, int fd)
{
    users_t *c1 = (users_t *) t1;

    dprintf(fd, "/users:%s:%s:%d", c1->name, c1->id, c1->status);
    usleep(200);
}

void dump_teams(void *t1, int fd)
{
    teams_t *c1 = (teams_t *) t1;

    dprintf(fd, "/lteam:%s:%s:%s", c1->id, c1->name, c1->description);
    usleep(200);
}

void dump_canal(void *t1, int fd)
{
    chanel_t *c1 = (chanel_t *) t1;

    dprintf(fd, "/lchan:%s:%s:%s", c1->id, c1->name, c1->description);
    usleep(200);
}

void dump_thread(void *t1, int fd)
{
    thread_t *c1 = (thread_t *) t1;

    dprintf(fd, "/lthr:%s:%s:%ld:%s:%s", c1->id,
    c1->creator_id,
    c1->date, c1->name, c1->body);
    usleep(200);
}

void dump_comment(void *t1, int fd)
{
    comment_t *c1 = (comment_t *) t1;

    dprintf(fd, "/lcmt:%s:%s:%ld:%s", c1->id, c1->creator_id,
    c1->date, c1->body);
    usleep(200);
}
