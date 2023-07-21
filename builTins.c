#include "shell.h"

/**
 * _toka- exit function
 * @args - argument pointer
 *
 * Return: o
 */
int _toka(char **args __attribute__((unused)));

char *inbuilts[] = {
	"exit"
};

int (*intbuilts[]) (char **) = {
&_toka
};

int _idadi_builtins()
{
	return sizeof(inbuilts) / sizeof(char *);
}


int _toka(char **args __attribute__((unused)))
{
	exit(0);
}
