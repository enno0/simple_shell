#include "shell.h"
/**
 * node_starts_withk_m - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_tk_m *node_starts_withk_m(list_tk_m *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_withk_m(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}
