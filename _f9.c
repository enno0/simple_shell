#include "shell.h"

/**
 * _myexitk_m - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _myexitk_m(info_tk_m *info)
{
    int exitcheck;

    if (info->argv[1]) /* If there is an exit arguement */
    {
        exitcheck = _erratoik_m(info->argv[1]);
        if (exitcheck == -1)
        {
            info->status = 2;
            print_errork_m(info, "Illegal number: ");
            _eputsk_m(info->argv[1]);
            _eputchark_m('\n');
            return (1);
        }
        info->err_num = _erratoik_m(info->argv[1]);
        return (-2);
    }
    info->err_num = -1;
    return (-2);
}
