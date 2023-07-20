#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int _strlen(char *str);
char *lineReader(char **buffer, size_t *bufsize);
int _strCmp(const char *str1, const char *str2);

#endif
