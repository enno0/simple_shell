#include "shell.h"
/**
 * print_errork_m - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_errork_m(info_tk_m *info, char *estr)
{
	_eputsk_m(info->fname);
	_eputsk_m(": ");
	print_dk_m(info->line_count, STDERR_FILENO);
	_eputsk_m(": ");
	_eputsk_m(info->argv[0]);
	_eputsk_m(": ");
	_eputsk_m(estr);
}
