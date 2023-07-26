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
	int p;

	if (ac != 1)
	{
		perror("Usage");
		exit(EXIT_FAILURE);
	}
	p = !isatty(0);
	while (1)
	{
		if (!p)
		{
			write(1, "#cisfun$ ", _strlen("#cisfun$ "));
			fflush(stdout);
		}
		retbuf = lineReader(&buffer, &bufsize);
		if (retbuf == NULL)
		{
			break;
		}
		executor(retbuf);
		if (p)
		{
			break;
		}
	}
	return (0);
}
