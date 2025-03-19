/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#pragma once
#include "server.h"
#include "../myteams/logging_client.h"
#include "list.h"
#include "users.h"

typedef struct teams {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char *id;
    char *creator_id;
    list_t *users;
    list_t *canal;
} teams_t;
