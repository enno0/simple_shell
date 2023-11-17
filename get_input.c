#include "shell.h"
/**
 * get_inputk_m - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_inputk_m(info_tk_m *info)
{
	static char *buf;
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchark_m(BUF_FLUSHk_m);
	r = input_bufk_m(info, &buf, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buf + i;

		check_chaink_m(info, buf, &j, i, len);
		while (j < len)
		{
			if (is_chaink_m(info, buf, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			info->cmd_buf_type = CMD_NORMk_m;
		}

		*buf_p = p;
		return (_strlenk_m(p));
	}

	*buf_p = buf;
	return (r);
}
