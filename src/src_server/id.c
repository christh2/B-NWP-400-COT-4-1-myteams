/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/server.h"
#include "../../libs/include/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <uuid/uuid.h>
#include "../../libs/include/teams.h"
#include "../../libs/include/users.h"
#include "../../libs/include/threads.h"
#include "../../libs/include/canal.h"

bool compare_username(void *client, void *username)
{
    return strcmp(((users_t *)client)->name, (char *)username) == 0;
}

char *generate_uuid(void)
{
    char *uuid_str = (char *)malloc(36);
    uuid_t uuid;

    uuid_generate(uuid);
    uuid_unparse(uuid, uuid_str);
    return uuid_str;
}
