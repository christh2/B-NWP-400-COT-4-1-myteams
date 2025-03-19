/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/server.h"
#include "../../libs/include/list.h"

void new_connect_handler(a_server_t *ftp)
{
    struct sockaddr_in addr_client;
    socklen_t size = sizeof(addr_client);
    int src = accept(ftp->fds.fd,
    (struct sockaddr *)&addr_client, &size);
    char str[] = "/welcome:220 Welcome to wave";
    client_t *client;

    FD_SET(src, &ftp->sets.my_fds);
    if (src > ftp->fds.max_fd)
        ftp->fds.max_fd = src;
    client = (client_t *)malloc(sizeof(client_t));
    client->ip = inet_ntoa(addr_client.sin_addr);
    client->port = ntohs(addr_client.sin_port);
    client->fd = src;
    client->user = NULL;
    list_add_elem_at_back(&ftp->client, client);
    write(src, str, strlen(str));
}

bool is_pair(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != 0; i++)
        if (str[i] == c && str[i + 1] != c)
            count++;
    return (count % 2) == 0;
}

void command_handler(a_server_t *ftp, int fd)
{
    char src[1024];
    int i = 0;
    client_t *tmp = list_get_elem_by_value(ftp->client, &fd, &compare_fds);
    int bytes = read(fd, src, 1024);

    if (bytes < 3)
        return;
    for (; src[i] != '\n'; i++);
    src[i] = '\0';
    if (!is_pair(src, '\"'))
        return;
    disconnected_cmd(src, fd, ftp);
    connected_cmd(src, fd, ftp);
}

int nb_args(char **tab)
{
    int i = 0;

    for (i = 0; tab[i] != NULL; i++);
    return (i);
}
