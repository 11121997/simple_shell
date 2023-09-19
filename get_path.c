#include "shell.h"

/**
 * *get_location - function take in command and return the path of it
 * @cmd: command to find it's path
 * Return: the path
 */
char *get_location(char *cmd)
{
	char *path, *path_cpy, *path_token, *file_path;
	int cmd_len, dir_len;
	struct stat buffer;

	path = _getenv("PATH");
	if (path)
	{
		path_cpy = _strdup(path);

		cmd_len = _strlen(cmd);

		path_token = strtok(path_cpy, ":");
		while (path_token != NULL)
		{
			dir_len = _strlen(path_token);
			file_path = malloc(cmd_len + dir_len + 2);

			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, cmd);
			_strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_cpy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_cpy);
		free(file_path);

		if (stat(cmd, &buffer) == 0)
			return (cmd);
		return (NULL);
	}
	return (NULL);
}
