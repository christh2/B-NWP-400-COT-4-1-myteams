/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/

#include "../../libs/include/server.h"

void users_command(int client_fd, a_server_t *server)
{
    list_dump(server->users, &dump_user, client_fd);
}

void disconnected_cmd(char *str, int fd, a_server_t *ftp)
{
    char **create_tab = fill_it(str, '\"');
    char **tab = fill_it(str, ' ');

    if (command_cmp(tab[0], "/help") == 0) {
        help_command(fd);
    }
    if (command_cmp(tab[0], "/logout") == 0) {
        logout_command(fd, ftp);
    }
    if (command_cmp(tab[0], "/login") == 0) {
        login_command(fd, create_tab, ftp);
    }
}

void connected_cmd_2(int fd, a_server_t *ftp, char **tab, char **create_tab)
{
    if (command_cmp(tab[0], "/use") == 0) {
        use_command(fd, create_tab, ftp);
    }
    if (command_cmp(tab[0], "/users") == 0) {
        users_command(fd, ftp);
    }
    if (command_cmp(tab[0], "/user") == 0) {
        user_command(fd, create_tab, ftp);
    }
    if (command_cmp(tab[0], "/subscribed") == 0) {
        subscribed_cmd(fd, create_tab, ftp);
    }
    if (command_cmp(tab[0], "/message") == 0) {
        if (tab[1] == NULL) {
            write(fd, "Inter user ID.\n", strlen("Inter user ID.\n"));
            return;
        } else {
            messages_command(fd, create_tab, ftp);
        }
    }
}

void connected_cmd_3(int fd, a_server_t *ftp, char **tab, char **create_tab)
{
    client_t *client = list_get_elem_by_value(ftp->client,
        &fd, &compare_fds);

    if (command_cmp(tab[0], "/info") == 0) {
        if (client != NULL) {
            info_command(fd, client, ftp);
        } else {
            dprintf(fd, "Client not found.\n");
            return;
        }
    }
    if (command_cmp(tab[0], "/subscribe") == 0)
        subscribe_cmd(fd, create_tab, ftp);
    if (command_cmp(tab[0], "/unsubscribe") == 0)
        unsubscribe_cmd(fd, create_tab, ftp);
}

void connected_cmd(char *str, int fd, a_server_t *ftp)
{
    char **create_tab = fill_it(str, '\"');
    char **tab = fill_it(str, ' ');

    if (command_cmp(tab[0], "/create") == 0)
        create_command(fd, create_tab, ftp);
    if (command_cmp(tab[0], "/list") == 0)
        list_command(fd, create_tab, ftp);
    if (command_cmp(tab[0], "/send") == 0) {
        send_command(fd, create_tab, ftp);
    }
    connected_cmd_2(fd, ftp, tab, create_tab);
    connected_cmd_3(fd, ftp, tab, create_tab);
    free_tab(create_tab);
    free_tab(tab);
}
