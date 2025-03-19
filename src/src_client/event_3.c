/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/proces.h"

void log_bteam(char **tab)
{
    client_error_unknown_team(tab[1]);
}

void team_created_event(char **tab)
{
    client_event_team_created(tab[1], tab[2], tab[3]);
}

void team_created(char **tab)
{
    client_print_team_created(tab[1], tab[2], tab[3]);
}

void already(char **tab)
{
    client_error_already_exist();
}
