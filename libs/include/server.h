/*
** EPITECH PROJECT, 2024
** ftp
** File description:
** ftp
*/
#pragma once
#include "list.h"
#include "client.h"
#include "../myteams/logging_server.h"
#include <dlfcn.h>

typedef struct a_server_t {
    struct sockaddr_in addr;
    select_set_t sets;
    f_desc_t fds;
    list_t *client;
    list_t *users;
    list_t *teams;
    list_t *messages;
} a_server_t;

int create_socket(void);
struct sockaddr_in init_sock_conf(int port, char *ip);
void bind_and_listen(struct sockaddr_in *addr, int fd, int len);
void new_connect_handler(a_server_t *ftp);
void command_handler(a_server_t *ftp, int fd);
void multi_server_handler(int port);
a_server_t init_my_server(int port);
int num_args(char *str, char *delim);
void free_tab(char **tab);
char **alloc_on_str(char *str, char sep);
char **fill_it(char *str, char sep);
void disconnected_cmd(char *str, int fd, a_server_t *ftp);
void connected_cmd(char *str, int fd, a_server_t *ftp);
void request_handler(int fd, a_server_t *ftp);
int nb_args(char **tab);
bool compare_fds(void *, void *);
char *generate_uuid(void);
void login_command(int fd, char **tab, a_server_t *ftp);
void quit_cmd(int fd, char **tab, a_server_t *ftp);
bool compare_teams_id(void *t1, void *t2);
bool compare_teams_name(void *t1, void *t2);
void dump_user(void *t1, int fd);
bool compare_uuid(void *client, void *uuid);
char *generate_uuid(void);
void user_command(int fd, char **tab, a_server_t *ftp);
void create_teams_command(int fd, char **tab, client_t *tmp, a_server_t *ftp);
void create_command(int fd, char **tab, a_server_t *ftp);
void use_command(int fd, char **tab, a_server_t *ftp);
void init_user(char *str, char *new_id, users_t *new_client);
bool compare_username(void *client, void *username);
void create_a_user(int fd, char *str, a_server_t *ftp);
void logged_a_user(int fd, users_t *existing_client, a_server_t *ftp);
void messages_command(int fd, char **tab, a_server_t *ftp);
void help_command(int fd);
void reset_context(client_t *tmp);
bool compare_chanel_id(void *t1, void *t2);
bool compare_thread_id(void *t1, void *t2);
bool compare_comment_id(void *t1, void *t2);
thread_t *init_thread(char *id, teams_t *team, chanel_t *canal);
chanel_t *init_canal(char *id, teams_t *team);
teams_t *init_team(char *id);
comment_t *init_cmt(char *id, teams_t *team, chanel_t *canal, thread_t *thr);
void list_command(int fd, char **tab, a_server_t *ftp);
void list_teams_command(int fd, char **tab, client_t *tmp, a_server_t *ftp);
void list_canal_command(int fd, char **tab, client_t *tmp, a_server_t *ftp);
void list_thread_command(int fd, char **tab, client_t *tmp, a_server_t *ftp);
void list_comment_command(int fd, char **tab, client_t *tmp, a_server_t *ftp);
void dump_teams(void *t1, int fd);
void dump_canal(void *t1, int fd);
void dump_thread(void *t1, int fd);
void dump_comment(void *t1, int fd);
void send_command(int fd, char **tab, a_server_t *ftp);
void load_user(a_server_t *ftp, FILE *file);
void load_data(a_server_t *ftp);
void load_teams(a_server_t *ftp);
void load_canals(a_server_t *ftp);
void load_thread(a_server_t *ftp);
void load_comment(a_server_t *ftp);
void save_teams(a_server_t *ftp);
void save_user(a_server_t *ftp);
void save_comment(teams_t *team, chanel_t *canal, thread_t *thr);
void save_thr(teams_t *team, chanel_t *canal);
void unsubscribe_cmd(int fd, char **tab, a_server_t *ftp);
void subscribe_cmd(int fd, char **tab, a_server_t *ftp);
void info_command(int fd, client_t *client, a_server_t *ftp);
void logout_command(int fd, a_server_t *server);
int command_cmp(const char *str1, const char *str2);
bool compare_client_id(void *t1, void *t2);
int get_status(list_t *list, char *id);
void create_team_event(int fd, teams_t *team, a_server_t *ftp);
void create_chanel_event(int fd, teams_t *team,
    chanel_t *canal, a_server_t *ftp);
void create_thr_event(int fd, teams_t *team, thread_t *thr, a_server_t *ftp);
void create_cmt_event(int fd, teams_t *team, comment_t *cmt, a_server_t *ftp);
void subscribed_cmd(int fd, char **tab, a_server_t *ftp);
void save_msg(a_server_t *ftp);
void load_msg(a_server_t *ftp);
void logout_print(users_t *user, a_server_t *server);
