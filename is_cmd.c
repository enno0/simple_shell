#include "shell.h"

/**
 * is_cmdk_m - determines if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmdk_m(info_tk_m *info, char *path)
{
	struct stat st;

	if (!path || stat(path, &st) != 0)
	{
		perror("is_cmdk_m"); // Add appropriate error handling
		return 0;
	}

	return S_ISREG(st.st_mode) ? 1 : 0;
}
