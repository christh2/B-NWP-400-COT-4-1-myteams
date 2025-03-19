/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercises
*/
#include "../../libs/include/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool list_del_elem_at_front(list_t **front_ptr)
{
    list_t *tmp = *front_ptr;

    if ((*front_ptr) == NULL)
        return false;
    (*front_ptr) = (*front_ptr)->next;
    free(tmp);
    return true;
}

bool list_del_elem_at_back(list_t **front_ptr)
{
    list_t *tmp = *front_ptr;
    list_t *del;

    if ((*front_ptr) == NULL)
        return false;
    if (tmp->next == NULL)
        return list_del_elem_at_front(front_ptr);
    while (tmp->next->next)
        tmp = tmp->next;
    del = tmp->next;
    tmp->next = NULL;
    free(del);
    return true;
}

bool list_del_elem_at_position(list_t **front_ptr,
    unsigned int position)
{
    list_t *tmp = *front_ptr;
    list_t *del;

    if ((*front_ptr) == NULL)
        return false;
    if (position == 0) {
        list_del_elem_at_front(front_ptr);
        return false;
    }
    for (unsigned int i = 0; i < (position - 1); i++) {
        if (tmp == NULL)
            return false;
        tmp = tmp->next;
    }
    del = tmp->next;
    tmp->next = tmp->next->next;
    free(del);
    return true;
}

void list_clear(list_t **front_ptr)
{
    list_t *tmp;

    if (*front_ptr == NULL)
        return;
    while ((*front_ptr)) {
        tmp = (*front_ptr);
        (*front_ptr) = (*front_ptr)->next;
        free(tmp);
    }
}

bool list_del_elem_by_value(list_t **list, void *vlue,
    bool(*func)(void *, void *))
{
    list_t *tmp = *list;
    list_t *del;

    if (list == NULL)
        return false;
    if (func(tmp->vlue, vlue))
        return list_del_elem_at_front(list);
    while (tmp->next) {
        if (tmp->next == NULL)
            return false;
        if (func(tmp->next->vlue, vlue))
            break;
        tmp = tmp->next;
    }
    del = tmp->next;
    tmp->next = tmp->next->next;
    free(del);
    return true;
}
