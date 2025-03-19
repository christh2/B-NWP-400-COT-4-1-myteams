/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercises 00, 01, 02 & 03
*/

#include "../../libs/include/list.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int list_get_size(list_t *list)
{
    list_t *tmp = list;
    unsigned int size = 0;

    while (tmp) {
        tmp = tmp->next;
        size++;
    }
    return size;
}

bool list_is_empty(list_t *list)
{
    if (list == NULL)
        return true;
    return false;
}

void list_dump(list_t *list, void(*val_disp)(void *, int), int fd)
{
    list_t *tmp = list;

    while (tmp) {
        val_disp(tmp->vlue, fd);
        tmp = tmp->next;
    }
}
