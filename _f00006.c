#include "shell.h"
/**
 * free_infok_m - frees info_tk_m struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void free_infok_m(info_tk_m *info, int all)
{
	ffreek_m(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_listk_m(&(info->env));
		if (info->history)
			free_listk_m(&(info->history));
		if (info->alias)
			free_listk_m(&(info->alias));
		ffreek_m(info->environ);
		info->environ = NULL;
		bfreek_m((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchark_m(BUF_FLUSHk_m);
	}
}
