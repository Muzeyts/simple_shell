#include "myshell.h"

/**
 * str_len - Calculate the length of a given string.
 * @string: string to be measured
 * Return: length of the string
 */
int str_len(char *string)
{
        int i = 0;

        while (string[i] != '\0')
        {
                i++;
        }
        return (i);
}
