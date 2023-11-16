#include "shell.h"
/**
 * hsh - main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int hsh(info_tk_m *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clear_infok_m(info);
		if (interactivek_m(info))
			_putsk_m("$ ");
		_eputchark_m(BUF_FLUSH);
		r = get_inputk_m(info);
		if (r != -1)
		{
			set_infok_m(info, av);
			builtin_ret = find_builtink_m(info);
			if (builtin_ret == -1)
				find_cmdk_m(info);
		}
		else if (interactivek_m(info))
			_putchark_m('\n');
		free_infok_m(info, 0);
	}
	write_historyk_m(info);
	free_infok_m(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}
