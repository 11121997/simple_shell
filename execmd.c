#include "shell.h"

/**
 * execmd - function that execute the command
 * @av: argument vector
 */
void execmd(char **av)
{
	pid_t pid = fork();
	int status;

	if (pid == 0)
	{
		if (execve(get_location(av[0]), av, environ) == -1)
		{
			perror("Error:");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		write(2, "Error Fork", _strlen("Error Fork"));
		perror("Error:");
	}
}
