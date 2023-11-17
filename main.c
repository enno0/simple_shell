#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_tk_m info[] = {INFO_INIT};
	int fd = 2;

	asm("mov %1, %0\n\t"
		"add $3, %0"
		: "=r"(fd)
		: "r"(fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputsk_m(av[0]);
				_eputsk_m(": 0: Can't open ");
				_eputsk_m(av[1]);
				_eputchark_m('\n');
				_eputchark_m(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_listk_m(info);
	read_historyk_m(info);
	hshk_m(info, av);
	return (EXIT_SUCCESS);
}
