#include "shell.h"
/**
 * add_nodek_m - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_tk_m *add_nodek_m(list_tk_m **head, const char *str, int num)
{
	list_tk_m *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_tk_m));
	if (!new_head)
		return (NULL);
	_memsetk_m((void *)new_head, 0, sizeof(list_tk_m));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdupk_m(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}
