/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#pragma once
#include "server.h"
#include "../myteams/logging_client.h"

typedef struct comment {
    char body[MAX_BODY_LENGTH];
    time_t date;
    char *id;
    char *creator_id;
    char *chanel_id;
    char *team_id;
    char *thread_id;
} comment_t;
