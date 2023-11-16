#include "shell.h"
/**
 * add_node_endk_m - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_tk_m *add_node_endk_m(list_tk_m **head, const char *str, int num)
{
	list_tk_m *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_tk_m));
	if (!new_node)
		return (NULL);
	_memsetk_m((void *)new_node, 0, sizeof(list_tk_m));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdupk_m(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}
