#include "shell.h"

/**
 * my_printenv - function that print environment list
 */
void my_printenv(void)
{
	char **env = environ;

	for (; *env; env++)
	{
		_puts(*env);
	}
}
