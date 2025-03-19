/*
** EPITECH PROJECT, 2024
** cpp project
** File description:
** MyTek 2 project
*/

#include "../../libs/include/server.h"

void help_command(int fd)
{
    char *help_message = "/help:Liste des commandes disponibles :\n"
                            "\t/help\n"
                            "\t/login [user_name]\n"
                            "\t/users\n"
                            "\t/user [user_uuid]\n"
                            "\t/logout : Se déconnecter du serveur\n"
                            "\t/send [user_uuid] [message_body]\n"
                            "\t/messages [user_uuid]\n"
                            "\t/subscribe [team_uuid]\n"
                            "\t/subscribed ?[team_uuid]\n"
                            "\t/unsubscribe [team_uuid] : Se "
                            "désabonner d'une équipe\n"
                            "\t/use ?[team_uuid] ?[channel_uuid] "
                            "?[thread_uuid]\n"
                            "\t/create\n"
                            "\t/list\n"
                            "\t/info\n";

    write(fd, help_message, strlen(help_message));
}
