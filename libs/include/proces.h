/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <errno.h>
#include <fcntl.h>
#include <dlfcn.h>
#include "../../libs/include/list.h"
#include "../myteams/logging_client.h"

#define BUFFER_SIZE 1024

int create_client_socket(const char *ip, int port);
void initialize_fds(fd_set *readfds, int client_socket);
int connect_to_server(int cli_s, const char *ip, int port);
void handle_server_input(int client_socket, bool *run);
void handle_user_input(int client_socket);
void handle_loop_client(int client_socket);
void team_log(char *line, bool *run);
void log_bsend(char **tab);
void log_user(char **tab);
void log_messages(char **tab);
void log_sub(char **tab);
void log_unsub(char **tab);
void log_login(char **tab);
void blogin(char **tab);
void log_logout(char **tab, bool *run);
void log_users(char **tab);
void log_send(char **tab);
void log_bteam(char **tab);
void team_created_event(char **tab);
void team_created(char **tab);
void already(char **tab);
void chanel_created_event(char **tab);
void chanel_created(char **tab);
void log_bchan(char **tab);
void cmt_created(char **tab);
void cmt_created_event(char **tab);
void thr_created_event(char **tab);
void thr_created(char **tab);
void list_team(char **tab);
void list_thr(char **tab);
void list_chan(char **tab);
void list_cmt(char **tab);
