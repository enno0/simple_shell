#include "shell.h"
/**
 * print_listk_m - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_listk_m(const list_tk_m *h)
{
	size_t i = 0;

	while (h)
	{
		_putsk_m(convert_numberk_m(h->num, 10, 0));
		_putchark_m(':');
		_putchark_m(' ');
		_putsk_m(h->str ? h->str : "(nil)");
		_putsk_m("\n");
		h = h->next;
		i++;
	}
	return (i);
}

