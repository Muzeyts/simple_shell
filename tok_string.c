#include "myshell.h"

static char *next_token;

/**
 * tok_str - our strtok to tokenize a string.
 * @str: the string to be tokenized.
 * @delim: the delimiter character.
 * Return: a pointer to the next token or NULL
 */
char *tok_str(char *str, char *delim)
{
	/* check the string */
	if (!str)
	{
		str = next_token;

		if (!str)
			return (NULL);
	}

	while (*str && *str == ' ')
		str++;

	next_token = stok_help(str, delim);

	return (str);
}

/**
 * delim_check - check if a character is a delimiter.
 * @charcheck: the character to be checked.
 * @delimstr: the string containing delimiter characters.
 * Return: 0 | 1 if the character is a delimiter
 */
int delim_check(char charcheck, char *delimstr)
{
	int postn = 0;

	while (delimstr[postn])
	{
		if (charcheck == delimstr[postn])
			return (1);
		postn++;
	}

	return (0);
}

/**
 * stok_help - - get the next token from a string.
 * @str: the string to tokenize.
 * @delim: the delimiter character.
 * Return: pointer to the next token or NULL.
 */
char *stok_help(char *str, char *delim)
{
	int i = 0;

	while (str[i])
	{
		if (delim_check(str[i], delim))
		{
			str[i] = '\0';

			while (delim_check(str[i + 1], delim))
			{
				str[i + 1] = '\0';
				i++;
			}

			if (str[i + 1] != '\0')
				return (&str[i + 1]);

			return (NULL);
		}

		i++;
	}

	return (NULL);
}
