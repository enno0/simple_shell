#include "shell.h"

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_aliask_m(list_tk_m *node)
{
    char *p = NULL, *a = NULL;

    if (node)
    {
        p = _strchrk_m(node->str, '=');
        for (a = node->str; a <= p; a++)
            _putchark_m(*a);
        _putchark_m('\'');
        _putsk_m(p + 1);
        _putsk_m("'\n");
        return (0);
    }
    return (1);
}
