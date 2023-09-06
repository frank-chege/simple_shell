#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

int begin(int argc, char **argv, char **env);
char *prompt_input(char **argv);
int _nmbr_value(char *input);
char **store_data(char *input, char **argv);
void run_cmd(char **value, char **argv, char **env);
int display_path(char **value, char **env);
char *_show_env(char **env, char *cmd);
void display_env(char **env);
void release_array(char **arr);
int _missing(char **cmd, char **env);
void quit_cmd(char **cmd);
int _str_size(char *str);
int _copy(char *end, char *str);
int _compare(char *str1, char *str2, size_t sz);
char *_concat(char *end, const char *str);
void _display(int position, char **argv, char *msg);
void _display_error(int position, char **argv, char *cmd);

#endif
