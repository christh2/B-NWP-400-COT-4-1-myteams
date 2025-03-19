/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#pragma once
#include "server.h"
#include "../myteams/logging_client.h"

typedef struct chanel {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char *id;
    char *creator_id;
    char *team_id;
    list_t *thread;
} chanel_t;
