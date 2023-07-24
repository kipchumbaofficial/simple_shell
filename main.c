#include "shell.h"
/**
 * main - Command executer and prompter
 * @ac: Argument count
 * @av: Argument Vector
 *
 * Return: 0
 */
int main(int ac, char **av __attribute__((unused)))
{
	char *args[100], *arguments[100];
	int  i, x, j;
	char *buffer = NULL, *retbuf, *path;
	size_t bufsize = 0;

	if (ac != 1)
	{
		perror("Usage");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		write(1, "#cisfun$ ", _strlen("#cisfun$ "));
		retbuf = lineReader(&buffer, &bufsize);
		if (retbuf == NULL)
			break;
		i = 0;
		args[i] = strtok(retbuf, "\n ");
		while (args[i] != NULL && i <= 99)
		{
			i++;
			args[i] = strtok(NULL, "\n ");
		}
		args[i] = NULL;
		path = pathFinder(args[0]);
		arguments[0] = path;
		j = 1;
		while (args[j] != NULL && i < 100)
		{
			arguments[j] = args[j];
			j++;
		}
		arguments[j] = NULL;
		if (_strCmp(args[0], "exit") == 0)
		{
			if (_toka(args) == -1)
				break;
		}
		if (fork() != 0)
		{
			wait(NULL);
		}
		else
		{
			x = execve(arguments[0], arguments, NULL);
			if (x == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
	}
	return (0);
}
