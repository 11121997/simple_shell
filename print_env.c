#include "shell.h"

/**
 * my_printenv - function that print environment list
 */
void my_printenv(void)
{
	char **env = environ;
	unsigned int i;

	for (i = 0; env[i] != NULL; i++)
	{
		_putchar(i);
	}
}
