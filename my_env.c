#include "shell.h"

/**
 * *_getenv - function that gets an environment variable
 * @environ: variable name
 * Return: a pointer to the value of environment variable
 */
char **_getenv(char **environ)
{
	unsigned int i = 0;
	char **env = NULL;
	char *actual_env = NULL;

	actual_env = strtok(environ[i], "=");
	while (environ[i])
	{
		if (_strcmp(actual_env, "PATH"))
		{
			actual_env = strtok(NULL, "\n");
			env = tokinzer(actual_env, ":");
			return (env);
		}
		i++;
		actual_env = strtok(environ[i], "=");
	}
	return (NULL);
}
/**
 * my_printenv - function that print environment list.
 * @environ: the environment variable.
 */
void my_printenv(char **environ)
{
	size_t len = 0;
	size_t i = 0;

	while (environ[i])
	{
		len = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
/**
 * tokinzer - splits a string and makes it an array of words.
 *
 * @str: string to be split.
 * @delim: delimiter.
 *
 * Return: array of  words.
 */

char **tokinzer(char *str, const char *delim)
{
	char *token = NULL, **av = NULL;
	size_t strsize = 0;
	int x = 0;

	if (str == NULL)
		return (NULL);
	strsize = _strlen(str);
	av = malloc((strsize + 1) * sizeof(char *));
	if (av == NULL)
	{
		perror("Unable to allocate buffer");
		free(str);
		free_argv(av);
		exit(EXIT_FAILURE);
	}

	token = strtok(str, delim);
	while (token != NULL)
	{
		av[x] = malloc(_strlen(token) + 1);
		if (av[x] == NULL)
		{
			perror("Unable to allocate buffer");
			free_argv(av);
			return (NULL);
		}
		_strcpy(av[x], token);
		token = strtok(NULL, delim);
		x++;
	}
	av[x] = NULL;
	return (av);
}
