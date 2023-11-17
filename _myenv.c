#include "shell.h"

/**
 * _myenvk_m - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenvk_m(info_tk_m *info)
{
    print_list_strk_m(info->env);
    return (0);
}