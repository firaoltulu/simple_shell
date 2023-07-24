#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

#include <sys/stat.h>

void Custom_send_to_free(char *one, char **two);

char *_strncpy(char *dest, char *src, int n);
unsigned int _strlen(char *str);
int _strcmp(char *s1, char *s2);

#endif
