#include "shell.h"
/**
 * lineReader - Read line from stdin
 * @buffer: Buffer to write to
 * @bufsize: Size of buffer;
 *
 * Return: Written buffer
 */
char *lineReader(char **buffer, size_t *bufsize)
{
	ssize_t characters;
	char *retbuf;

	characters = getline(buffer, bufsize, stdin);
	if (characters == -1)
	{
		return (NULL);
	}
	retbuf = *buffer;
	return (retbuf);
}
