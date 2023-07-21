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
/**
 *strDup - Dublicates string
 *@str: string to be duplicated
 *
 * Return: Duplicate
 *
 */
char *strDup(char *str)
{
	int i, len;
	char *dup;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	dup = malloc(sizeof(char) * len + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/**
 *strCpy - Copies string
 * @src: initial string
 * @dest: destination of string
 *
 * Return: Destination
 */

char *strCpy(char *dest, char *src)
{
	int i, length;

	length = _strlen(src);
	for (i = 0; i < length && *src != '\0'; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * strCat -Concatenates string
 * @str1: string to be appended
 * @str2: destination string
 *
 * Return: str2
 */
char *strCat(char *str2, char *str1)
{
	int i, j;

	i = 0;

	while (*str2 != '\0')
	{
		i++;
	}
	j = 0;

	while (str1[j] != '\0')
	{
		str2[i] = str1[j];
		i++;
		j++;
	}
	str2[i] = '\0';
	return (str2);
}
