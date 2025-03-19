/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/proces.h"

void log_1(char *line, char **tab, bool *bol)
{
    if (strcmp(tab[0], "/login") == 0)
        log_login(tab);
    if (strcmp(tab[0], "/blogin") == 0)
        blogin(tab);
    if (strcmp(tab[0], "/help") == 0)
        printf("%s\n", line + 6);
    if (strcmp(tab[0], "/welcome") == 0)
        printf("%s\n", line + 9);
    if (strcmp(tab[0], "/logout") == 0)
        log_logout(tab, bol);
    if (strcmp(tab[0], "/users") == 0)
        log_users(tab);
    if (strcmp(tab[0], "/send") == 0)
        log_send(tab);
    if (strcmp(tab[0], "/bid") == 0)
        log_bsend(tab);
    if (strcmp(tab[0], "/user") == 0)
        log_user(tab);
}

void log_2(char *line, char **tab, bool *bol)
{
    if (strcmp(tab[0], "/msg") == 0)
        log_messages(tab);
    if (strcmp(tab[0], "/sub") == 0)
        log_sub(tab);
    if (strcmp(tab[0], "/unsub") == 0)
        log_unsub(tab);
    if (strcmp(tab[0], "/bteam") == 0)
        log_bteam(tab);
    if (strcmp(tab[0], "/cre_team") == 0)
        team_created(tab);
    if (strcmp(tab[0], "/e_cre_team") == 0)
        team_created_event(tab);
    if (strcmp(tab[0], "/already") == 0)
        already(tab);
}

void log_3(char *line, char **tab, bool *bol)
{
    if (strcmp(tab[0], "/cre_chan") == 0)
        chanel_created(tab);
    if (strcmp(tab[0], "/cre_thr") == 0)
        thr_created(tab);
    if (strcmp(tab[0], "/cre_cmt") == 0)
        cmt_created(tab);
    if (strcmp(tab[0], "/e_cre_chan") == 0)
        chanel_created_event(tab);
    if (strcmp(tab[0], "/e_cre_thr") == 0)
        thr_created_event(tab);
    if (strcmp(tab[0], "/e_cre_cmt") == 0)
        cmt_created_event(tab);
    if (strcmp(tab[0], "/lteam") == 0)
        list_team(tab);
    if (strcmp(tab[0], "/lchan") == 0)
        list_chan(tab);
    if (strcmp(tab[0], "/lthr") == 0)
        list_thr(tab);
    if (strcmp(tab[0], "/lcmt") == 0)
        list_cmt(tab);
}

void team_log(char *line, bool *bol)
{
    char **tab = fill_it(line, ':');

    log_1(line, tab, bol);
    log_2(line, tab, bol);
    log_3(line, tab, bol);
    free_tab(tab);
}
