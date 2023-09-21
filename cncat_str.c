#include "myshell.h"

/**
 * cncat_str - two strings will be concatenated.
 * @destination: pointer to the destination string.
 * @source: pointer to the source string.
 * Return: pointer to the concatenated string.
 */

char *cncat_str(char *destination, char *source)
{
	int x = 0, y;

	while (destination[x] != '\0')
	{
		x++;
	};

	y = 0;

	while (source[y] != '\0')
	{
		destination[x] = source[y];
		x++;
		y++;
	};

	return (destination);
}

/**
 * cmp_str - two string will be compared.
 * @str1: First input string
 * @str2: Second input string
 *
 * Return: str1[x] - str2[x]
 * or 0 if the strings are identical.
 */
int cmp_str(const char *str1, char *str2)
{
	int x = 0;

	while (str1[x] != '\0' && str2[x] != '\0')
	{
		if (str1[x] != str2[x])
		{
			return (str1[x] - str2[x]);
		}
		x++;
	}
	return (0);
}
