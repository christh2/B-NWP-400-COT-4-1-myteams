/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/server.h"

int create_socket(void)
{
    return socket(AF_INET, SOCK_STREAM, 0);
}

void bind_and_listen(struct sockaddr_in *addr, int fd, int len)
{
    if (bind(fd, (struct sockaddr *)addr, len) < 0) {
        printf("Bind failed\n");
        exit(84);
    }
    if (listen(fd, 100) < 0) {
        printf("Listening failed\n");
        exit(84);
    }
}

void select_error(int res)
{
    if (res < 0) {
        printf("Fork error\n");
        exit(84);
    }
}

bool compare_fds(void *t1, void *t2)
{
    client_t *c1 = (client_t *) t1;
    int *c2 = (int *) t2;

    if (c1->fd == *c2)
        return true;
    return false;
}

struct sockaddr_in init_sock_conf(int port, char *ip)
{
    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);
    return addr;
}
