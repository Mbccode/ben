#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
/*#include <sys/wait.h>*/
#include <sys/stat.h>


int _getc(FILE *input);
ssize_t _getline(char **_get, size_t *nget, FILE *input);
char *_strchr(const char *strGet, int charGet);
char *_strpbrk(const char *strGet, const char *strSET);
char *strtok_help(char *str, const char *delim);
char *_strtok(char *str, const char *delim);

#endif
