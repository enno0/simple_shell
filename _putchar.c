#include "shell.h"
/**
 * _putchark_m - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchark_m(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZEk_m];

	if (c == BUF_FLUSHk_m || i >= WRITE_BUF_SIZEk_m)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSHk_m)
		buf[i++] = c;
	return (1);
}
