/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#pragma once
#include "../myteams/logging_client.h"
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <sys/select.h>
#include <dirent.h>
#include "teams.h"
#include "users.h"
#include "threads.h"
#include "canal.h"
#include "commentary.h"
#include "message.h"
#include <time.h>
#include <fcntl.h>

typedef struct select_set {
    fd_set my_fds;
    fd_set readable_fds;
} select_set_t;

typedef struct f_desc {
    int fd;
    int max_fd;
    int data_fd;
} f_desc_t;

typedef struct logger {
    bool user;
    bool password;
    bool pasv_port;
} logger_t;

typedef struct client {
    logger_t login;
    int port;
    char *ip;
    int fd;
    users_t *user;
} client_t;
