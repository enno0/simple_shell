#include "shell.h"

/**
 * unset_aliask_m - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_aliask_m(info_tk_m *info, char *str)
{
    char *p, c;
    int ret;

    p = _strchrk_m(str, '=');
    if (!p)
        return (1);
    c = *p;
    *p = 0;
    ret = delete_node_at_indexk_m(&(info->alias),
                                  get_node_indexk_m(info->alias, node_starts_withk_m(info->alias, str, -1)));
    *p = c;
    return (ret);
}