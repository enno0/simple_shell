#include "shell.h"

/**
 * _myenvk_m - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenvk_m(info_tk_m *info)
{
	print_list_strk_m(info->env);
	return (0);
}

/**
 * _getenvk_m - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenvk_m(info_tk_m *info, const char *name)
{
	list_tk_m *node = info->env;
	char *p;

	while (node)
	{
		p = starts_withk_m(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenvk_m - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenvk_m(info_tk_m *info)
{
	if (info->argc != 3)
	{
		_eputsk_m("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenvk_m(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenvk_m - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenvk_m(info_tk_m *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputsk_m("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenvk_m(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_listk_m - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_listk_m(info_tk_m *info)
{
	list_tk_m *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_endk_m(&node, environ[i], 0);
	info->env = node;
	return (0);
}
