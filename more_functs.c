#include "myshell.h"

/**
 * trim_spaces - Trim leading and trailing spaces from a string.
 * @string: the input string.
 * Return: Nothing
 */
void trim_spaces(char *string)
{
	int start = 0;
	int end = str_len(string) - 1;
	int x;

	while (isspace(string[start]))
	{
		start++;
	}

	while (end >= start && isspace(string[end]))
	{
		end--;
	}

	for (x = 0; x <= end - start; x++)
	{
		string[x] = string[start + x];
	}

	string[x] = '\0';
}

/**
 * contains_forward_slash - forward slash is checked in the string.
 * @string: the input string.
 * Return: 0 if success
 */
int contains_forward_slash(const char *string)
{
	int x;

	for (x = 0; string[x] != '\0'; x++)
	{
		if (string[x] == '/')
		{
			return (1);
		}
	}
	return (0);
}

/**
 * split_str - splits a string into slices based on delimiters.
 * @input: the string to be split.
 * Return: an array of slices.
 */
char **split_str(char *input)
{
	char **result;
	char *delimiter = " \t\n";
	char *token = tok_str(input, delimiter);
	int i = 0;
	int sz = 100;

	result = malloc(sizeof(char *) * sz);

	while (token != NULL)
	{
		result[i] = token;
		token = tok_str(NULL, delimiter);
		i++;
	}
	result[i] = NULL;

	result = realloc(result, sizeof(char *) * (i + 1));

	return (result);
}

/**
 * find_path - get the path to a command executable.
 * @cmd: this is the command to find in the PATH.
 * Return: pointer (output: command program path)
 */
char *find_path(char *cmd)
{
	char *path_env = find_env("PATH");
	char *token;
	char *result;
	struct stat fl_st;

	token = tok_str(path_env, ":");
	while (token)
	{
		result = malloc(str_len(token) + str_len(cmd) + 2);
		cpy_str(result, token);
		cncat_str(result, "/");
		cncat_str(result, cmd);
		if (stat(result, &fl_st) == 0)
			return (result);
		free(result);
		token = tok_str(NULL, ":");
	}

	return (NULL);
}
