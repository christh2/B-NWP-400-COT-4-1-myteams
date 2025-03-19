/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/proces.h"

void cmt_created(char **tab)
{
    client_print_reply_created(tab[1], tab[2],
    (time_t)atoi(tab[3]), tab[4]);
}

void cmt_created_event(char **tab)
{
    client_event_thread_reply_received(tab[1],
    tab[2], tab[3], tab[4]);
}

void list_team(char **tab)
{
    client_print_teams(tab[1], tab[2], tab[3]);
}

void list_chan(char **tab)
{
    client_team_print_channels(tab[1], tab[2], tab[3]);
}

void list_thr(char **tab)
{
    client_channel_print_threads(tab[1], tab[2],
    (time_t)atoi(tab[3]), tab[4], tab[5]);
}
