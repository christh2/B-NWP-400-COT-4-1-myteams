/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#pragma once
#include "server.h"
#include "../myteams/logging_client.h"

typedef struct users {
    char name[MAX_NAME_LENGTH];
    char *id;
    char *team;
    char *canal;
    char *thread;
    int status;
} users_t;
