#include "shell.h"
/**
 * lineReader - Read line from stdin
 * @buffer: Buffer to write to
 * @bufsize: Size of buffer
 *
 * Return: Written buffer
 */
char *lineReader(char **buffer, size_t *bufsize)
{
	char *retbuf;
	ssize_t characters;

	characters = getline(buffer, bufsize, stdin);
	if (characters == -1)
	{
		free(*buffer);
		return (NULL);
	}
	retbuf = *buffer;
	if (retbuf[characters - 1] == '\n')
	{
		retbuf[characters - 1] = '\0';
	}
	return (retbuf);
}
