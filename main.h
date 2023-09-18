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

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

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
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* string_4.c functions */
char **_strtow(char *str, char *d);
char **_strtow2(char *str, char d);

/* memory.c functions */
char *_memset(char *s, char b, unsigned int n);
void _freess(char **pp);
int _freenull(void **p);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* getlin.c functions */ 
/*
   ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);
*/

#define DATA_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *					allowing uniform prototype for function pointer struct
 * @line: a string generated from getline containing arguements
 * @argv: an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()s
 * @linecount_flag: if on count this line of input
 * @file_name: the program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @histcount: the history line number count
 */
typedef struct passdata
{
	char *line;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *file_name;
/*	list_t *env;
	list_t *history;
	list_t *alias;*/
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;

} data_t;

/**
 * struct built_in - list of builtins
 * @name: The specifier
 * @f: The function associated with printing
 */
typedef struct built_in
{
	char *name;
	int (*f)(data_t *);

} builtin_t;

/* functions.c functions */
int interactive(data_t *data);
int is_delim(char c, char *delim);
int _isalpha(int c);
void remove_comments(char *buf);
int _atoi(char *s);

/* functions_2.c functions */

/* data.c functions */
void clear_data(data_t *data);
void set_data(data_t *data, char **av);
void free_data(data_t *data, int all);



void is_builtin(data_t *data);

extern char **environ;

char **split(char *string);

void execute(data_t *data);
int _exit_shell(data_t *data);
char *_which(char *command);

/* env.c functions */
int env(data_t *data);
int set_env(char *name, char *value, int overwite);
int _setenv(data_t *data);

#endif
