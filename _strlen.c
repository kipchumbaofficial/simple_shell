#include "shell.h"
/**
 * _strlen - Gets the length of the string
 * @str: String to get length
 *
 *
 * Return: Length
 */
int _strlen(char *str)
{
	if (*str == '\0')
	{
		return (0);
	}
	return (1 + _strlen(str + 1));
}
