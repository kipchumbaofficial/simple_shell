#include "shell.h"
/**
 * _getenv - Get environment variables
 * @name: Name of variable
 *
 * Return: Value of the variable
 */
extern char **environ;

char *_getenv(char *name)
{
	char *retval = NULL;
	char **envi;
	int len = _strlen(name);

	for (envi = environ; *envi != NULL; envi++)
	{
		if (strncmp(*envi, name, len) == 0 && (*envi)[len] == '=')
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
	char *njia, *njia_dup, *token, *file_link;
	int cmd_len = _strlen(command), dir_len;
	struct stat buffer;

	njia = _getenv("PATH");
	if (njia)
	{
		njia_dup = strDup(njia);
		token = strtok(njia_dup, ":");

		while (token != NULL)
		{
			dir_len = _strlen(token);
			file_link = malloc(cmd_len + dir_len + 2);
			strCpy(file_link, token);
			strCat(file_link, "/");
			strCat(file_link, command);
			strCat(file_link, "\0");
			if (stat(file_link, &buffer) == 0)
			{
				free(njia_dup);
				return (file_link);
			}
			else
			{
				free(file_link);
				token = strtok(NULL, ":");
			}
		}
		free(njia_dup);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
