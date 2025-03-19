/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/

#include "../../libs/include/server.h"

bool compare_client_id(void *t1, void *t2)
{
    client_t *tmp = (client_t *)t1;

    if (!tmp->user)
        return false;
    return strcmp(tmp->user->id, (char *)t2) == 0;
}

int get_status(list_t *list, char *id)
{
    client_t *tmp = list_get_elem_by_value(list, id, compare_client_id);

    if (tmp == NULL)
        return 0;
    return 1;
}
