#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/wait.h>

/**
 * struct custom_list - Linked list containing PATH directories.
 * @direct: directory in path.
 * @point: pointer to next node.
 */
typedef struct custom_list
{
    char *direct;
    struct custom_list *point;
} custom_list;

/**
 * struct custom - custom corresponding
 * to build in command.
 * @command: buildin command.
 * @func: execute the buildin command.
 */
typedef struct custom
{
    char *command;
    void (*func)(char **);
} custom;

extern char **environ;

int _strlen(char *one);
int _putchar(char c);
void _puts(char *one);
char *_strdup(char *one);
char *concat_all(char *one, char *two, char *three);

char *custom__getenv(const char *one);
custom_list *custom_linkpath(char *one);
char *custom_which(char *one, custom_list *two);

void *custom__reallocate(void *one, unsigned int two, unsigned int three);

void (*custom_check_build(char **arv))(char **arv);
void custom_build_exit(char **one);
void custom_build_env(char **one __attribute__((unused)));
void custom_build_setenv(char **one);
void custom_build_unsetenv(char **one);

void custom_free_arv(char **one);

#endif
