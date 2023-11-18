#include "shell.h"

/**
 * get_history_filek_m - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containg history file
 */

char *get_history_filek_m(info_tk_m *info)
{
	char *buf, *dir;

	dir = _getenvk_m(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlenk_m(dir) + _strlenk_m(HIST_FILEk_m) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpyk_m(buf, dir);
	_strcatk_m(buf, "/");
	_strcatk_m(buf, HIST_FILEk_m);
	return (buf);
}

/**
 * write_historyk_m - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int write_historyk_m(info_tk_m *info)
{
	ssize_t fd;
	char *filename = get_history_filek_m(info);
	list_tk_m *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfdk_m(node->str, fd);
		_putfdk_m('\n', fd);
	}
	_putfdk_m(BUF_FLUSHk_m, fd);
	close(fd);
	return (1);
}

/**
 * read_historyk_m - reads history from file
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int read_historyk_m(info_tk_m *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_filek_m(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_listk_m(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_history_listk_m(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAXk_m)
		delete_node_at_indexk_m(&(info->history), 0);
	renumber_historyk_m(info);
	return (info->histcount);
}

/**
 * build_history_listk_m - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int build_history_listk_m(info_tk_m *info, char *buf, int linecount)
{
	list_tk_m *node = NULL;

	if (info->history)
		node = info->history;
	add_node_endk_m(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_historyk_m - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int renumber_historyk_m(info_tk_m *info)
{
	list_tk_m *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}
