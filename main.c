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
	char *buffer = NULL, *retbuf;
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
		executor(retbuf);
	}
	return (0);
}
