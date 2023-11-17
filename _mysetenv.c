#include "shell.h"

/**
 * _mysetenvk_m - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenvk_m(info_tk_m *info)
{
    if (info->argc != 3)
    {
        _eputsk_m("Incorrect number of arguements\n");
        return (1);
    }
    if (_setenvk_m(info, info->argv[1], info->argv[2]))
        return (0);
    return (1);
}