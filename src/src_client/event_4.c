/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/proces.h"

void chanel_created_event(char **tab)
{
    client_event_channel_created(tab[1], tab[2], tab[3]);
}

void thr_created_event(char **tab)
{
    client_event_thread_created(tab[1], tab[2],
    (time_t)atoi(tab[3]), tab[4], tab[5]);
}

void chanel_created(char **tab)
{
    client_print_channel_created(tab[1], tab[2], tab[3]);
}

void thr_created(char **tab)
{
    client_print_thread_created(tab[1], tab[2],
    (time_t)atoi(tab[3]), tab[4], tab[5]);
}

void log_bchan(char **tab)
{
    client_error_unknown_channel(tab[1]);
}
