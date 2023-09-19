#include "shell.h"

/**
 * *_getenv - function that gets an environment variable
 * @name: variable name
 * Return: a pointer to the value of environment variable
 */
char *_getenv(const char *name)
{
	char **env;
	char *actual_env;
	int i;

	for (env = environ; *env != NULL; env++)
	{
		actual_env = *env;
		for (i = 0; actual_env[i] != '=' ; i++)
		{
			if (name[i] != actual_env[i])
			{
				break;
			}
		}
		if (actual_env[i] == '=' && name[i] == '\0')
		{
			return (actual_env + i + 1);
		}
	}
	return (NULL);
}
