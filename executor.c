#include "myshell.h"

/**
 * execute_args - function to execute a command.
 * @args: arguments to be executed.
 * @envp: env variables.
 * Return: Nothing.
 */
void execute_args(char **args, char **envp)
{
        pid_t pid;
        int status, exec_result;
        char *exec_command;

        pid = fork();
        if (pid == 0)
        {
                if (contains_forward_slash(args[0]) == 0 && strstr(args[0], "hbtn") == NULL)
                {
                        exec_command = find_path(args[0]);
                        exec_result = execve(exec_command, args, envp);
                }
                else
                {
                        exec_result = execve(args[0], args, envp);
                }

                if (exec_result == -1)
                {
                        perror("./shell");
                        exit(EXIT_FAILURE);
                }
                exit(EXIT_SUCCESS);
        }
        else if (pid > 0)
        {
                waitpid(pid, &status, 0);

                if (WIFEXITED(status))
                {
                        int exit_status = WEXITSTATUS(status);

                        if (exit_status != 0)
                        {
                                exit(2);
                        }
                }
        }
        free(args);
}
