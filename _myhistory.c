#include "shell.h"

/**
 * _myhistoryk_m - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistoryk_m(info_tk_m *info)
{
    print_listk_m(info->history);
    return (0);
}