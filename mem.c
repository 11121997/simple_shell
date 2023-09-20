#include "shell.h"

/**
 * free_argv - frees the array of pointers av
 *
 *@av: array of pointers.
 */

void free_argv(char **av)
{
	size_t i;

	if (av == NULL)
	{
		return;
	}

	for (i = 0; av[i]; i++)
		free(av[i]);

	if (av[i] == NULL)
	{
		free(av[i]);
	}

	free(av);
}

/**
 * exit_free - function that frees all the memory allocated and exit.
 *
 * @av: pointer to allocated command memory to free.
 */
void exit_free(char **av)
{
	size_t i = 0;

	if (av == NULL)
		return;

	while (av[i])
	{
		free(av[i]);
		i++;
	}

	if (av[i] == NULL)
		free(av[i]);
	free(av);
	exit(EXIT_FAILURE);
}

/**
 * a_to_i - ASCII to integer
 *
 *@str: pointer to a string
 *
 *Return: the int.
 */
int a_to_i(char *str)
{
	int x = 0;
	int y = 0;
	int s = 1;

	while (!((str[x] >= '0') && (str[x] <= '9')) && (str[x] != '\0'))
	{
		if (str[x] == '-')
		{
			s = s * (-1);
		}
		x++;
	}
	while ((str[x] >= '0') && (str[x] <= '9'))
	{
		y = (y * 10) + (s * (str[x] - '0'));
		x++;
	}
	return (y);
}
