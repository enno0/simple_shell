#include "shell.h"

/**
 * _myhelpk_m - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelpk_m(info_tk_m *info)
{
	char **arg_array;

	arg_array = info->argv;
	_putsk_m("help call works. Function not yet implemented \n");
	if (0)
		_putsk_m(*arg_array); /* temp att_unused workaround */
	return (0);
}
