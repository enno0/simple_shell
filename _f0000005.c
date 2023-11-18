#include "shell.h"

/**
 * set_aliask_m - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_aliask_m(info_tk_m *info, char *str)
{
    char *p;

    p = _strchrk_m(str, '=');
    if (!p)
        return (1);
    if (!*++p)
        return (unset_aliask_m(info, str));

    unset_aliask_m(info, str);
    return (add_node_endk_m(&(info->alias), str, 0) == NULL);
}
