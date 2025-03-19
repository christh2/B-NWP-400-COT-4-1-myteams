/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#pragma once
#include "server.h"
#include "../myteams/logging_client.h"

typedef struct thread {
    char name[MAX_NAME_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t date;
    char *id;
    char *creator_id;
    char *chanel_id;
    char *team_id;
    list_t *comment;
} thread_t;
