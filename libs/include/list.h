/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#pragma once
#include <stdbool.h>
#include <string.h>

typedef struct list {
    void *vlue;
    struct list *next;
} list_t;

void *list_get_elem_at_front(list_t *list);
void *list_get_elem_at_back(list_t *list);
void *list_get_elem_at_position(list_t *list, unsigned int position);
void *list_get_elem_by_value(list_t *list, void *vlue,
    bool(*func)(void *, void *));
unsigned int list_get_size(list_t *list);
bool list_is_empty(list_t *list);
void list_dump(list_t *list, void(*val_disp)(void *, int), int fd);
bool list_del_elem_at_front(list_t **front_ptr);
bool list_del_elem_at_back(list_t **front_ptr);
bool list_del_elem_at_position(list_t **front_ptr,
    unsigned int position);
bool list_del_elem_by_value(list_t **list, void *vlue,
    bool(*func)(void *, void *));
void list_clear(list_t **front_ptr);
bool list_add_elem_at_front(list_t **front_ptr, void *elem);
bool list_add_elem_at_position(list_t **front_ptr,
    void *elem, unsigned int position);
bool list_add_elem_at_back(list_t **front_ptr, void *elem);
char **fill_it(char *str, char sep);
void free_tab(char **tab);
