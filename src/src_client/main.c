/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/proces.h"
#include "../../libs/include/server.h"

void error_case(int act)
{
    if (act < 0) {
        perror("select error");
        exit(84);
    }
}

void handle_loop_client(int client_socket)
{
    fd_set readfds;
    int activity;
    int max_fd = client_socket;
    size_t len = 0;
    bool run = true;

    while (run) {
        initialize_fds(&readfds, client_socket);
        activity = select(max_fd + 1, &readfds, NULL, NULL, NULL);
        error_case(activity);
        if (FD_ISSET(client_socket, &readfds))
            handle_server_input(client_socket, &run);
        if (FD_ISSET(STDIN_FILENO, &readfds))
            handle_user_input(client_socket);
    }
}

int main(int argc, char **argv)
{
    char *server_ip;
    int server_port;
    int client_socket;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s [server_ip] [server_port]\n", argv[0]);
        exit(84);
    }
    server_ip = argv[1];
    server_port = atoi(argv[2]);
    client_socket = create_client_socket(server_ip, server_port);
    connect_to_server(client_socket, server_ip, server_port);
    handle_loop_client(client_socket);
    return 0;
}
