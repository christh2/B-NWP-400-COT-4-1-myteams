/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/server.h"
#include "../../libs/include/teams.h"
#include "../../libs/include/list.h"

bool compare_teams_id(void *t1, void *t2)
{
    return strcmp(((teams_t *)t1)->id, (char *)t2) == 0;
}

bool compare_teams_name(void *t1, void *t2)
{
    return strcmp(((teams_t *)t1)->name, (char *)t2) == 0;
}

bool compare_chanel_id(void *t1, void *t2)
{
    return strcmp(((chanel_t *)t1)->id, (char *)t2) == 0;
}

bool compare_thread_id(void *t1, void *t2)
{
    return strcmp(((thread_t *)t1)->id, (char *)t2) == 0;
}

bool compare_comment_id(void *t1, void *t2)
{
    return strcmp(((comment_t *)t1)->id, (char *)t2) == 0;
}
