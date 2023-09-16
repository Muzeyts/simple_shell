#include "myshell.h"

void run_function(char *cmd_line, ssize_t read_line, char **env);

/**
 * run_function - run function to process and execute commands.
 * @cmd_line: user input command line.
 * @read_line: read line status.
 * @env: env variables.
 * Return: Nothing
 */
void run_function(char *cmd_line, ssize_t read_line, char **env)
{
	char **args;

	if (str_len(cmd_line) == 0 || str_len(cmd_line) == 1)
	{
		free(cmd_line);
		exit(EXIT_SUCCESS);
	}
	if (read_line == -1)
	{
		free(cmd_line);
		exit(EXIT_SUCCESS);
	}
	args = split_str(cmd_line);
	if (cmp_str(args[0], "exit") == 0)
	{
		free(args);
		free(cmd_line);
		exit(EXIT_SUCCESS);
	}
	else if (cmp_str(args[0], "cd") == 0)
	{
		change_directory(args[1]);
		free(args);
	}
	else if (cmp_str(args[0], "env") == 0)
	{
		print_env(args);
		free(args);
	}
	else
		execute_args(args, env);
}


/**
 * main - the entry point for program execution
 * @argc: the number of arguments
 * @argv: array of arguments
 * @env: env variables
 * Return: Always returns 0
 */
int main(int argc, char *argv[], char **env)
{
	char *input_line = NULL;
	size_t line_length = 0;
	ssize_t line_read;
	(void)argc;
	(void)argv;

	while (true)
	{
		line_read = getline(&input_line, &line_length, stdin);
		trim_spaces(input_line);
		run_function(input_line, line_read, env);
	}
	return (0);
}
