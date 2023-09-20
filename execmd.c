#include "shell.h"

/**
 * execmd - function that execute the command
 * @av: argument vector
 * @name: pointer to name
 * @environ: pointer to environmental variables
 * @n: executed times
 */
void execmd(char **av, char *name, char **environ, int n)
{
	unsigned int i = 0;
	char **pname = NULL;
	char *fpath = NULL;
	struct stat st;

	if (_strcmp(av[0], "env") != 0)
		my_printenv(environ);
	if (stat(av[0], &st) == 0)
	{
		if (execve(av[0], av, environ) < 0)
		{
			perror(name);
			exit_free(av);
		}
	}
	else
	{
		pname = _getenv(environ);
		while (pname[i])
		{
			fpath = _strcat(pname[i], av[0]);
			i++;
			if (stat(fpath, &st) == 0)
			{
				if (execve(fpath, av, environ) < 0)
				{
					perror(name);
					free_argv(pname);
					exit_free(av);
				}
				return;
			}
		}
		handle_errors(name, n, av);
		free_argv(pname);
	}
}

/**
 * chd - function that chande working directory
 * @path: new current working directory
 * Return: 0 on success, -1 on failure
 */
int chd(const char *path)
{
	char *buf = NULL;
	size_t size = 1024;

	if (path == NULL)
		path = getcwd(buf, size);
	else if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}

/**
 * child_process - function creats a sub process
 * @av: argument vector
 * @name: pointer to name
 * @environ: pointer to environmental variables
 * @n: number of executed times
 */
void child_process(char **av, char *name, char **environ, int n)
{
	int pid = 0;
	int st = 0;
	int mirr = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		exit_free(av);
	}
	else if (pid == 0)
	{
		execmd(av, name, environ, n);
		free_argv(av);
	}
	else
	{
		mirr = waitpid(pid, &st, 0);
		if (mirr < 0)
		{
			exit_free(av);
		}
		free_argv(av);
	}
}

/**
 * handle_errors - function handle errors
 * @name: name of shell
 * @av: argument vector
 * @n: number of times
 */
void handle_errors(char *name, int n, char **av)
{
	char t;

	t = n + '0';

	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &t, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, av[0], _strlen(av[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
