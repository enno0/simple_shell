#include "shell.h"
/**
 * clear_infok_m - initializes info_tk_m struct
 * @info: struct address
 */
void clear_infok_m(info_tk_m *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

