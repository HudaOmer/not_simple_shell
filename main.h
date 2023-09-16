#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>


/* string.c functions */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_startwith(const char *string, const char *substring);
char *_strcat(char *dest, char *src);
void printarray(char **array);

/* string_2.c functions */
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* string_3.c functions */




/**
 * struct built_in - list of builtins
 * @bi: The specifier
 * @f: The function associated with printing
 */
typedef struct built_in
{
	char *name;
	int (*f)();
} builtin_t;

void is_builtin(char **argv, char *fn);

extern char **environ;

char **split(char *string);

void execute(char **argv, char *file_name);
int _exit_shell(void);
char *_which(char *command);

int env(void);

#endif
