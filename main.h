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
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

/* for read/write */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096
#define BUFSIZE 1024
extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;


/**
 * struct passdata - all data needed
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
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;

} data_t;

#define DATA_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

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

void my_shell(data_t *data, char **argv);
int tokenization(data_t *data, char **argv);

/* err_puts.c functions */
void _eputs(char *);
int putc_to_stderr(char);
int putc_to_fd(char c, int fd);
int puts_to_fd(char *str, int fd);
void cant_open(int __attribute__((unused)) ac, char **argv);

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

/* functions.c functions */
int interactive(data_t *data);
int is_delim(char c, char *delim);
int _isalpha(int c);
void remove_comments(char *buf);
int _atoi(char *s);

/* functions_2.c functions */
int _erratoi(char *s);
void print_error(data_t *data, char *estr);
int printd(int input, int fd);
char *convert_number(long int num, int base, int flags);

/* getline2.c functions */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* data.c functions */
void clear_data(data_t *data);
void set_data(data_t *data, char **av);
void free_data(data_t *data, int all);

/* env.c functions */
int print_env(data_t *data);
int set_env(data_t *data, char *name, char *value, int overwrite);
int _setenv(data_t *data);
char *_getenv(data_t *data, const char *name);

/* env2.c functions */
int unset_env(data_t *data, char *name);
int _unsetenv(data_t *data);
int pop_env(data_t *data);

/* file_io.c functions */
char *get_history_file(data_t *data);
int write_history(data_t *data);
int read_history(data_t *data);
int build_history_list(data_t *data, char *buf, int linecount);
int renumber_history(data_t *data);

/* lists.c functions */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* lists_2.c functions */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* chain.c functions */
int is_chain_del(data_t *, char *, size_t *);
void chain_cont(data_t *, char *, size_t *, size_t, size_t);
int replace_alias(data_t *);
int replace_vars(data_t *);
int replace_str(char **, char *);

char *_getenv_var(const char *name);
void get_sigint(int sig);
void print_number(int n);

int is_builtin(data_t *data);
char **split(char *string);
void execute(data_t *data);
int _exit_shell(data_t *data);
char *_which(char *data);
int shell(data_t *data, char **argv);
void cant_open(int __attribute__((unused)) ac, char **argv);

#endif
