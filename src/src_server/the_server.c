/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/server.h"

a_server_t *pointer;

void init_lists(a_server_t *ftp)
{
    ftp->client = NULL;
    ftp->users = NULL;
    ftp->teams = NULL;
    ftp->messages = NULL;
}

a_server_t init_my_server(int port)
{
    a_server_t ftp;
    socklen_t len;

    ftp.fds.fd = create_socket();
    ftp.addr = init_sock_conf(port, "127.0.0.1");
    FD_ZERO(&ftp.sets.my_fds);
    FD_ZERO(&ftp.sets.my_fds);
    FD_SET(ftp.fds.fd, &ftp.sets.my_fds);
    ftp.fds.max_fd = ftp.fds.fd;
    len = sizeof(ftp.addr);
    bind_and_listen(&ftp.addr, ftp.fds.fd, len);
    init_lists(&ftp);
    return ftp;
}

void request_handler(int fd, a_server_t *ftp)
{
    pid_t pid;

    if (!FD_ISSET(fd, &ftp->sets.readable_fds))
        return;
    if (fd == ftp->fds.fd) {
        new_connect_handler(ftp);
    } else
        command_handler(ftp, fd);
}

void handler(int sig)
{
    save_user(pointer);
    save_teams(pointer);
    exit(0);
}

void multi_server_handler(int port)
{
    a_server_t ftp = init_my_server(port);
    int res;

    load_data(&ftp);
    pointer = &ftp;
    while (1) {
        ftp.sets.readable_fds = ftp.sets.my_fds;
        res = select(ftp.fds.max_fd + 1, &ftp.sets.readable_fds,
        NULL, NULL, NULL);
        for (int fd = 0; fd <= ftp.fds.max_fd; fd++)
            request_handler(fd, &ftp);
        signal(SIGINT, handler);
    }
    close(ftp.fds.fd);
}
