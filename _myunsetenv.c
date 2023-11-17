#include "shell.h"

/**
 * _myunsetenvk_m - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain constant function prototype.
 *  Return: Always 0
 */
int _myunsetenvk_m(info_tk_m *info)
{
    int i;

    if (info->argc == 1)
    {
        _eputsk_m("Too few arguements.\n");
        return (1);
    }
    for (i = 1; i <= info->argc; i++)
        _unsetenvk_m(info, info->argv[i]);

    return (0);
}
