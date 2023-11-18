#include "shell.h"

/**
 * get_environk_m - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_environk_m(info_tk_m *info)
{
    if (!info->environ || info->env_changed)
    {
        info->environ = list_to_stringsk_m(info->env);
        info->env_changed = 0;
    }

    return (info->environ);
}