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
			write(2, "Execute command failed.\n", _strlen("Execute command failed.\n"));
		}
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		if (waitpid(pid, &status, WUNTRACED) == -1)
		{
			perror("waitpid");
			write(2, "Error waitpid.\n" , _strlen("Error waitpid.\n"));
		}
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror("Error:");
		write(2, "Fork failed.\n", _strlen("Fork failed.\n"));
	}
}
