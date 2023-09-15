#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* string.c functions */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char _startwith(const char *string, const char *substring);
char *_strcat(char *dest, char *src);
void printarray(char **array);

/* string_2.c functions */


char **split(char *string);

void execute(char **argv, char *file_name);
void _exit_shell(char *line);

char *_which(char *command);

int env(void);

#endif
