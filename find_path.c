#include "shell.h"
/**
 * find_pathk_m - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_pathk_m(info_tk_m *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlenk_m(cmd) > 2) && starts_withk_m(cmd, "./"))
	{
		if (is_cmdk_m(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_charsk_m(pathstr, curr_pos, i);
			if (!*path)
				_strcatk_m(path, cmd);
			else
			{
				_strcatk_m(path, "/");
				_strcatk_m(path, cmd);
			}
			if (is_cmdk_m(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
