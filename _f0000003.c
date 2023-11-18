#include "shell.h"
/**
 * read_bufk_m - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t read_bufk_m(info_tk_m *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZEk_m);
	if (r >= 0)
		*i = r;
	return (r);
}
