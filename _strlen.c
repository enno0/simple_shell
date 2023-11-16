#include "shell.h"

/**
 * _strlenk_m - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlenk_m(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

