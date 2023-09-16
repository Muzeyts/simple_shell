#include "myshell.h"

/**
 * my_putchar - writes a character to stdout
 * @character: The character to be printed
 *
 * Return: OOn success, it returns 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int my_putchar(char character)
{
        return (write(1, &character, 1));
}

/**
 * str_puts - prints a string followed by a newline character.
 * @string: input string to be printed.
 * Return: no return.
 */
void str_puts(char *string)
{
        int i = 0;

        while (i >= 0)
        {
                if (string[i] == '\0')
                {
                        my_putchar('\n');
                        break;
                }
                my_putchar(string[i]);
                i++;
        }
}
