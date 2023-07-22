#include "shell.h"

/**
 * _toka- exit function
 * _idadi_builtins - number of builtins
 * @args: argument pointer
 *
 * Return: 0
 */
int _toka(char **args);

char *inbuilts[] = {
	"exit"
};

int (*intbuilts[]) (char **) = {
&_toka
};

int _idadi_builtins(void)
{
	return (sizeof(inbuilts) / sizeof(char *));
}



int _toka(char **args __attribute__((unused)))
{
	return (-1);
}
