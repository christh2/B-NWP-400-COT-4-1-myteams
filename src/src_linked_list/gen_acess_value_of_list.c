/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercises 00, 01, 02 & 03
*/
#include "../../libs/include/list.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void *list_get_elem_at_front(list_t *list)
{
    if (list == NULL)
        return 0;
    return list->vlue;
}

void *list_get_elem_at_back(list_t *list)
{
    list_t *tmp = list;

    if (list == NULL)
        return 0;
    while (tmp->next)
        tmp = tmp->next;
    return tmp->vlue;
}

void *list_get_elem_at_position(list_t *list, unsigned int position)
{
    list_t *tmp = list;
    unsigned int offset = 0;

    if (list == NULL)
        return 0;
    while (offset < position) {
        if (tmp == NULL)
            return 0;
        tmp = tmp->next;
        offset++;
    }
    return tmp->vlue;
}

void *list_get_elem_by_value(list_t *list, void *vlue,
    bool(*func)(void *, void *))
{
    list_t *tmp = list;

    if (list == NULL) {
        return NULL;
    }
    while (tmp) {
        if (func(tmp->vlue, vlue)) {
            return tmp->vlue;
        }
        tmp = tmp->next;
    }
    return NULL;
}
