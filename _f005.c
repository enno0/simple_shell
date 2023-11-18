#include "shell.h"

/**
 * _strlenk_m - returns the length of a string
 * @k: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlenk_m(char *k)
{
	int i = 0;

	if (!k)
		return (0);

	while (*k++)
		i++;
	return (i);
}
