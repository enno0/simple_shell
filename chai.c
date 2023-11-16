#include "shell.h"

/**
 * is_chaink_m - test if current char in buffer is a chain delimeter
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chaink_m(info_tk_m *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chaink_m - checks we should continue chaining based on last status
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void check_chaink_m(info_tk_m *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_aliask_m(info_tk_m *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_withk_m(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchrk_m(node->str, '=');
		if (!p)
			return (0);
		p = _strdupk_m(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_varsk_m - replaces vars in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_varsk_m(info_tk_m *info)
{
	int i = 0;
	list_tk_m *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmpk_m(info->argv[i], "$?"))
		{
			replace_stringk_m(&(info->argv[i]),
				_strdupk_m(convert_numberk_m(info->status, 10, 0)));
			continue;
		}
		if (!_strcmpk_m(info->argv[i], "$$"))
		{
			replace_stringk_m(&(info->argv[i]),
				_strdupk_m(convert_numberk_m(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_withk_m(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_stringk_m(&(info->argv[i]),
				_strdupk_m(_strchrk_m(node->str, '=') + 1));
			continue;
		}
		replace_stringk_m(&info->argv[i], _strdupk_m(""));

	}
	return (0);
}

/**
 * replace_stringk_m - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_stringk_m(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
