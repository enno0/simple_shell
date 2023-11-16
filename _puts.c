#include "shell.h"
/**
 *_putsk_m - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _putsk_m(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchark_m(str[i]);
		i++;
	}
}
