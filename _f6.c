#include "shell.h"

/**
 * _myaliask_m - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myaliask_m(info_tk_m *info)
{
	int i = 0;
	char *p = NULL;
	list_tk_m *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_aliask_m(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchrk_m(info->argv[i], '=');
		if (p)
			set_aliask_m(info, info->argv[i]);
		else
			print_aliask_m(node_starts_withk_m(info->alias, info->argv[i], '='));
	}

	return (0);
}
