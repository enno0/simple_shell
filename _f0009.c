#include "shell.h"
/**
 * ffreek_m - frees a string of strings
 * @pp: string of strings
 */
void ffreek_m(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}
