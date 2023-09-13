#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int _strlen(char *s);

char **split(char *string);

void execute(char **argv);

char *_which(char *command);

#endif
