#include "shell.h"
/**
 * list_to_stringsk_m - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_stringsk_m(list_tk_m *head)
{
	list_tk_m *node = head;
	size_t i = list_lenk_m(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlenk_m(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpyk_m(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}
