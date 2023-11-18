#include "shell.h"
/**
 * list_lenk_m - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t list_lenk_m(const list_tk_m *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}
