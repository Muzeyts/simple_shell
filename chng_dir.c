#include "myshell.h"

/**
 * change_directory - Change the current working directory.
 * @path: Represents the destination (or file name).
 * Return: Nothing.
 */
void change_directory(char *path)
{
	if (path == NULL)
	{
		chdir("/");
	}
	else
	{
		/* change the directory */
		if (chdir(path) != 0)
			str_puts("cd: No such file or directory");
	}
}
