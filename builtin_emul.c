#include "shell.h"

/**
 * _myhistoryk_m - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistoryk_m(info_tk_m *info)
{
	print_listk_m(info->history);
	return (0);
}

/**
 * unset_aliask_m - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_aliask_m(info_tk_m *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchrk_m(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_indexk_m(&(info->alias),
		get_node_indexk_m(info->alias, node_starts_withk_m(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_aliask_m - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_aliask_m(info_tk_m *info, char *str)
{
	char *p;

	p = _strchrk_m(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_aliask_m(info, str));

	unset_aliask_m(info, str);
	return (add_node_endk_m(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_aliask_m(list_tk_m *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchrk_m(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchark_m(*a);
		_putchark_m('\'');
		_putsk_m(p + 1);
		_putsk_m("'\n");
		return (0);
	}
	return (1);
}

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
