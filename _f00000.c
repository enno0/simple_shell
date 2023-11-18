#include "shell.h"
/**
 * interactivek_m - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactivek_m(info_tk_m *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

