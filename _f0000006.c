#include "shell.h"
/**
 * set_infok_m - initializes info_tk_m struct
 * @info: struct address
 * @av: argument vector
 */
void set_infok_m(info_tk_m *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtowk_m(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdupk_m(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		replace_aliask_m(info);
		replace_varsk_m(info);
	}
}

