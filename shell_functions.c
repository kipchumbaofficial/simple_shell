#include "shell.h"
/**
 *strNcmp - compares two strings
 *@str1: string one
 *@str2: string two
 *@n: number of characters
 *
 *Return: 0 on success
 */
int strNcmp(char *str1, char *str2, size_t n)
{
	size_t d;

	for (d = 0; d < n && str1[d] != '\0' && str2[d] != '\0'; d++)
	{
		if (str1[d] != str2[d])
			return (str1[d] - str2[d]);
	}
	return (0);
}

/**
 * executor - Shell execve
 * @buffer: String containing commands
 *
 * Return: Nothing
 */
void executor(char *buffer)
{
	char *args[100];
	int i, x;
	char *path;

	i = 0;
	args[i] = strtok(buffer, " \n");
	if (args[i] == NULL)
		return;
	while (args[i] != NULL && i <= 99)
	{
		i++;
		args[i] = strtok(NULL, " \n");
	}
	args[i] = NULL;
	if (_strCmp(args[0], "exit") == 0)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	path = pathFinder(args[0]);
	if (path == NULL)
	{
		perror("./shell");
		return;
	}
	if (fork() != 0)
	{
		wait(NULL);
	}
	else
	{
		x = execve(path, args, environ);
		if (x == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	if (isatty(0))
		free(path);
}

/**
 * _getenv - Get environment variables
 * @name: Name of variable
 *
 * Return: Value of the variable
 */

char *_getenv(char *name)
{
	char *retval = NULL;
	char **envi;
	int len = _strlen(name);

	for (envi = environ; *envi != NULL; envi++)
	{
		if (strNcmp(*envi, name, len) == 0 && (*envi)[len] == '=')
		{
			retval = *envi + len + 1;
			break;
		}
	}
	return (retval);
}
/**
 * pathFinder - Gets path of a command
 * @command: Command to get its full path
 *
 * Return: 0
 */
char *pathFinder(char *command)
{
	char *njia, *njia_dup, *token, *file_link, *file_path = NULL;
	int cmd_len = _strlen(command), dir_len;
	struct stat buffer;

	if (stat(command, &buffer) == 0)
		return (command);
	njia = _getenv("PATH");
	if (njia)
	{
		njia_dup = strDup(njia);
		token = strtok(njia_dup, ":");
		while (token != NULL)
		{
			dir_len = _strlen(token);
			file_link = malloc(cmd_len + dir_len + 2);
			if (file_link == NULL)
				return (NULL);
			strCpy(file_link, token);
			strCat(file_link, "/");
			strCat(file_link, command);
			strCat(file_link, "\0");
			if (stat(file_link, &buffer) == 0)
			{
				file_path = file_link;
				break;
			}
			else
			{
				free(file_link);
				token = strtok(NULL, ":");
			}
		}
		free(njia_dup);
	}
	if (file_path)
	{
		return (file_path);
	}
	return (NULL);
}
