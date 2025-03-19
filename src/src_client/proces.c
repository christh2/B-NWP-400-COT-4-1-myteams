/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#include "../../libs/include/proces.h"

int create_client_socket(const char *ip, int port)
{
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket == -1) {
        perror("Erreur création socket");
        exit(84);
    }
    return client_socket;
}

void initialize_fds(fd_set *readfds, int client_socket)
{
    FD_ZERO(readfds);
    FD_SET(client_socket, readfds);
    FD_SET(STDIN_FILENO, readfds);
}

int connect_to_server(int cli_s, const char *ip, int port)
{
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);
    if (connect(cli_s, (struct sockaddr *)&server_addr,
        sizeof(server_addr)) == -1) {
        perror("Erreur connexion au serveur");
        close(cli_s);
        exit(84);
    }
    return cli_s;
}

void handle_server_input(int client_socket, bool *run)
{
    int bytes;
    char buffer[BUFFER_SIZE];

    bytes = read(client_socket, buffer, BUFFER_SIZE);
    if (bytes > 0) {
        buffer[bytes] = '\0';
        team_log(buffer, run);
    }
}

void handle_user_input(int client_socket)
{
    char buffer[BUFFER_SIZE];
    int bytes;

    bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);
    if (bytes > 0) {
        buffer[bytes] = '\0';
        write(client_socket, buffer, bytes);
    }
}
