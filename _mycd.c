#include "shell.h"

/**
 * _mycdk_m - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mycdk_m(info_tk_m *info)
{
    char *s, *dir, buffer[1024];
    int chdir_ret;

    s = getcwd(buffer, 1024);
    if (!s)
        _putsk_m("TODO: >>getcwd failure emsg here<<\n");
    if (!info->argv[1])
    {
        dir = _getenvk_m(info, "HOME=");
        if (!dir)
            chdir_ret = /* TODO: what should this be? */
                chdir((dir = _getenvk_m(info, "PWD=")) ? dir : "/");
        else
            chdir_ret = chdir(dir);
    }
    else if (_strcmpk_m(info->argv[1], "-") == 0)
    {
        if (!_getenvk_m(info, "OLDPWD="))
        {
            _putsk_m(s);
            _putchark_m('\n');
            return (1);
        }
        _putsk_m(_getenvk_m(info, "OLDPWD=")), _putchark_m('\n');
        chdir_ret = /* TODO: what should this be? */
            chdir((dir = _getenvk_m(info, "OLDPWD=")) ? dir : "/");
    }
    else
        chdir_ret = chdir(info->argv[1]);
    if (chdir_ret == -1)
    {
        print_errork_m(info, "can't cd to ");
        _eputsk_m(info->argv[1]), _eputchark_m('\n');
    }
    else
    {
        _setenvk_m(info, "OLDPWD", _getenvk_m(info, "PWD="));
        _setenvk_m(info, "PWD", getcwd(buffer, 1024));
    }
    return (0);
}