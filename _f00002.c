#include "shell.h"
/**
 * find_builtink_m - finds a builtin command
 * @info: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int find_builtink_m(info_tk_m *info)
{
	int i, built_in_ret = -1;
	builtin_tablek_m builtintbl[] = {
		{"exit", _myexitk_m},
		{"env", _myenvk_m},
		{"help", _myhelpk_m},
		{"history", _myhistoryk_m},
		{"setenv", _mysetenvk_m},
		{"unsetenv", _myunsetenvk_m},
		{"cd", _mycdk_m},
		{"alias", _myaliask_m},
		{NULL, NULL}};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmpk_m(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	return (built_in_ret);
}
