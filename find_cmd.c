#include "shell.h"
/**
 * find_cmdk_m - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void find_cmdk_m(info_tk_m *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!is_delimk_m(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_pathk_m(info, _getenvk_m(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmdk_m(info);
	}
	else
	{
		if ((interactivek_m(info) || _getenvk_m(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmdk_m(info, info->argv[0]))
			fork_cmdk_m(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_errork_m(info, "not found\n");
		}
	}
}

