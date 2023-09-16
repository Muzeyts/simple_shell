#ifndef MYSHELL_H_
#define MYSHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

/*string_puts*/
void str_puts(char *string);
int my_putchar(char character);

/*change_directory*/
void change_directory(char *path);

/*env*/
void print_env(char **arguments __attribute__ ((unused)));
char *find_env(const char *target_env);

/*tok_string*/
int delim_check(char charcheck, char *delimstr);
char *stok_help(char *str, char *delim);
char *tok_str(char *str, char *delim);

/*more_functions*/
char **split_str(char *input);
char *find_path(char *cmd);
void trim_spaces(char *string);
int contains_forward_slash(const char *string);

/*string_len*/
int str_len(char *string);

/*concatenates string*/
char *cncat_str(char *destination, char *source);
int cmp_str(const char *str1, char *str2);

/*copy_string*/
char *cpy_str(char *destination, char *source);

/*executor*/
void execute_args(char **args, char **envp);

char *my_getline(void);

#endif
