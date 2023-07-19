#include <string.h>
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
	char *args[100];
	int x, i, characters;
	char *buffer = NULL;
	char *prompt = "#cisfun$ ";
	size_t bufsize = 0;

	if (ac != 1)
	{
		perror("Usage");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		write (1, prompt, _strlen(prompt));
		characters = getline(&buffer, &bufsize, stdin);
		if (characters == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		i = 0;
		args[i] = strtok(buffer, "\n");
		while (args[i] != NULL && i <= 99)
		{
			i++;
			args[i] = strtok(NULL, "\n");
		}
		args[i] = NULL;
		if (strcmp(args[0], "^C") == 0)
		{
			break;
		}
		if (fork() != 0)
		{
			wait(NULL);
		}
		else
		{
			x = execve(args[0], args, NULL);
			if (x == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
	}
		return (0);
}
