#include "shell.h"

/**
 * _setenvk_m - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int _setenvk_m(info_tk_m *info, char *var, char *value)
{
	char *buf = NULL;
	list_tk_m *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlenk_m(var) + _strlenk_m(value) + 2);
	if (!buf)
		return (1);
	_strcpyk_m(buf, var);
	_strcatk_m(buf, "=");
	_strcatk_m(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_withk_m(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_endk_m(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
