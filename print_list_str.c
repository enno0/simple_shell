#include "shell.h"
/**
 * print_list_strk_m - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_strk_m(const list_tk_m *h)
{
	size_t i = 0;

	while (h)
	{
		_putsk_m(h->str ? h->str : "(nil)");
		_putsk_m("\n");
		h = h->next;
		i++;
	}
	return (i);
}
