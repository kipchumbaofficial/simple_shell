#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

int _strlen(char *str);
char *lineReader(char **buffer, size_t *bufsize);
int _strCmp(const char *str1, const char *str2);
char *pathFinder(char *command);
char *strDup(char *str);
char *strCpy(char *dest, char *src);
char *strCat(char *str2, char *str1);
int _toka(char **args __attribute__((unused)));
#endif
