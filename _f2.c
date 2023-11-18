#include "shell.h"

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
