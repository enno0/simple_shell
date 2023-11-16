#include "shell.h"
/**
 * sigintHandlerk_m - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandlerk_m(__attribute__((unused))int sig_num)
{
	_putsk_m("\n");
	_putsk_m("$ ");
	_putchark_m(BUF_FLUSH);
}
