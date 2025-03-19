/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#pragma once
#include "server.h"
#include "../myteams/logging_client.h"

typedef struct msg {
    char body[MAX_BODY_LENGTH];
    time_t date;
    char *sender_id;
    char *receiver_id;
} msg_t;
