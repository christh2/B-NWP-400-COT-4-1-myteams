/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/proces.h"

void list_cmt(char **tab)
{
    client_thread_print_replies(tab[1],
    tab[2], (time_t)atoi(tab[3]), tab[4]);
}
