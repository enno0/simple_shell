#include "shell.h"

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
