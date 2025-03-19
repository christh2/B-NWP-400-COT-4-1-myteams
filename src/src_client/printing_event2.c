/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/proces.h"

void log_bsend(char **tab)
{
    client_error_unknown_user(tab[1]);
}

void log_user(char **tab)
{
    client_print_user(tab[1], tab[2], atoi(tab[3]));
}

void log_messages(char **tab)
{
    client_private_message_print_messages(tab[1],
    (time_t)atoi(tab[2]), tab[3]);
}

void log_sub(char **tab)
{
    client_print_subscribed(tab[1], tab[2]);
}

void log_unsub(char **tab)
{
    client_print_unsubscribed(tab[1], tab[2]);
}
