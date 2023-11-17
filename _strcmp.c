#include "shell.h"
/**
 * _strcmpk_m - performs lexicogarphic comparison of two strangs.
 * @k1: the first strang
 * @k2: the second strang
 *
 * Return: negative if k1 < k2, positive if k1 > k2, zero if k1 == k2
 */
int _strcmpk_m(char *k1, char *k2)
{
	while (*k1 && *k2)
	{
		if (*k1 != *k2)
			return (*k1 - *k2);
		k1++;
		k2++;
	}
	if (*k1 == *k2)
		return (0);
	else
		return (*k1 < *k2 ? -1 : 1);
}
