#include "shell.h"
/**
 * signalHandler - Handles signals
 * @signalnum: signal number
 */
void signalHandler(int signalnum __attribute__((unused)))
{
	write(1, "\n#cisfun$ ", _strlen("\n#cisfun$ "));
}
/**
 * main - Command executer and prompter
 * @ac: Argument count
 * @av: Argument Vector
 *
 * Return: 0
 */
int main(int ac, char **av __attribute__((unused)))
{
	char *buffer, *retbuf, *enter = "\n";
	size_t bufsize = 120;
	int p;

	if (ac != 1)
	{
		perror("Usage");
		exit(EXIT_FAILURE);
	}
	buffer = malloc(bufsize);
	if (buffer == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	signal(SIGINT, signalHandler);
	p = isatty(0);
	while (1)
	{
		if (p)
		{
			write(1, "#cisfun$ ", _strlen("#cisfun$ "));
			fflush(stdout);
		}
		retbuf = lineReader(&buffer, &bufsize);
		if (retbuf == NULL)
		{
			write(1, enter, _strlen(enter));
			exit(EXIT_SUCCESS);
		}
		executor(retbuf);
		if (!p)
		{
			break;
		}
	}
	free(buffer);
	return (0);
}
