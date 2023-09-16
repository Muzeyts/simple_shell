#include "myshell.h"

/**
 * char *cpy_str - Copy a string from src to dest.
 * @destination: dest to copy to
 * @source: source string to copy from
 * Return: to the copied string
 */
char *cpy_str(char *destination, char *source)
{
        int x = 0, y = 0;

        while (*(source + x) != '\0')
        {
                x++;
        }
        for ( ; y < x ; y++)
        {
                destination[y] = source[y];
        }
        destination[x] = '\0';
        return (destination);
}
