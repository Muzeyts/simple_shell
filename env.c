#include "myshell.h"

/**
 * print_env - prints the environment variables.
 * @arguments: Command-line arguments
 */
void print_env(char **arguments __attribute__ ((unused)))
{

	int i = 0;

	for (; environ[i]; i++)
	{
		str_puts(environ[i]);
	}

}

/**
 * find_env - searches for env variables
 * @target_env: the env variable to find
 * Return: a pointer to the string containing the result
 */
char *find_env(const char *target_env)
{
	int i = 0;
	char *token;
	char *result = NULL;

	while (environ[i])
	{
		token = tok_str(environ[i], "=");
		if (cmp_str(target_env, token) == 0)
		{
			result = tok_str(NULL, "\n");
			break;
		}
		i++;
	}

	while (token != NULL)
	{
		token = tok_str(NULL, "=");
	}

	return (result);
}
