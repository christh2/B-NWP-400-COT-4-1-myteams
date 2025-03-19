/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercises 00, 01, 02 & 03
*/

#include "../../libs/include/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool list_add_elem_at_front(list_t **front_ptr, void *elem)
{
    list_t *new_node = (list_t *)malloc(sizeof(list_t));
    list_t *tmp = *front_ptr;

    new_node->vlue = elem;
    if (new_node == NULL)
        return false;
    if (tmp == NULL) {
        new_node->next = NULL;
        *front_ptr = new_node;
        return true;
    }
    new_node->next = *front_ptr;
    *front_ptr = new_node;
    return true;
}

bool list_add_elem_at_position(list_t **front_ptr,
    void *elem, unsigned int position)
{
    list_t *tmp = *front_ptr;
    list_t *new_node = (list_t *)malloc(sizeof(list_t));

    if (new_node == NULL)
        return false;
    new_node->vlue = elem;
    if (position == 0) {
        list_add_elem_at_front(front_ptr, elem);
        return true;
    }
    for (unsigned int i = 0; i < (position - 1); i++) {
        if (tmp == NULL)
            return false;
        tmp = tmp->next;
    }
    new_node->next = tmp->next;
    tmp->next = new_node;
    return true;
}

bool list_add_elem_at_back(list_t **front_ptr, void *elem)
{
    list_t *new_node = (list_t *)malloc(sizeof(list_t));
    list_t *tmp = *front_ptr;

    if (new_node == NULL)
        return false;
    new_node->vlue = elem;
    new_node->next = NULL;
    if ((*front_ptr) == NULL) {
        *front_ptr = new_node;
        return true;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new_node;
    return true;
}
