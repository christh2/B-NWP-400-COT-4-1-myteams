/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/proces.h"

void log_login(char **tab)
{
    client_event_logged_in(tab[1], tab[2]);
}

void blogin(char **tab)
{
    client_error_unauthorized();
}

void log_logout(char **tab, bool *run)
{
    client_event_logged_out(tab[1], tab[2]);
}

void log_users(char **tab)
{
    client_print_users(tab[1], tab[2], atoi(tab[3]));
}

void log_send(char **tab)
{
    client_event_private_message_received(tab[1], tab[2]);
}
