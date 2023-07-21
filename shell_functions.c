#include "shell.h"
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

	njia = getenv("PATH");
	if (njia)
	{
		njia_dup = strdup(njia);
		token = strtok(njia_dup, ":");

		while (token != NULL)
		{
			dir_len = _strlen(token);
			file_link = malloc(cmd_len + dir_len + 2);
			strcpy(file_link, token);
			strcat(file_link, "/");
			strcat(file_link, command);
			strcat(file_link, "\0");
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
