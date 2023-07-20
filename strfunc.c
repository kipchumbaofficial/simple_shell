#include "shell.h"
/**
 * _strlen - Gets string length
 * @str: String to get length
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
/**
 * _strCmp - Compares 2 strings
 * @str1: First string
 * @str2: 2nd string
 *
 * Return: 0 on success -1 otherwise
 */
int _strCmp(const char *str1, const char *str2)
{
	while (*str1 == *str2)
	{
		if (*str1 == '\0' || *str2 == '\0')
		{
			break;
		}
		str1++;
		str2++;
	}
	if (*str1 == '\0' && *str2 == '\0')
	{
		return (0);
	}
	return (-1);
}
