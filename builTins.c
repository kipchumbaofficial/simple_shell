#include "shell.h"

/**
 * _toka- exit function
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

int _toka(char **args __attribute__((unused)))
{
	return (-1);
}
