#include "shell.h"

/**
 * get_environk_m - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_environk_m(info_tk_m *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_stringsk_m(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenvk_m - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenvk_m(info_tk_m *info, char *var)
{
	list_tk_m *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_withk_m(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_indexk_m(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

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
