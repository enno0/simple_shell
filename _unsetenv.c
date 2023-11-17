#include "shell.h"

/**
 * _unsetenvk_m - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenvk_m(info_tk_m *info, char *var)
{
    list_tk_m *node = info->env;
    size_t i = 0;
    char *p;

    if (!node || !var)
        return (0);

    while (node)
    {
        p = starts_withk_m(node->str, var);
        if (p && *p == '=')
        {
            info->env_changed = delete_node_at_indexk_m(&(info->env), i);
            i = 0;
            node = info->env;
            continue;
        }
        node = node->next;
        i++;
    }
    return (info->env_changed);
}