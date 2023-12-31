#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <linux/stat.h>

/* for read/write buffers */
#define READ_BUF_SIZEk_m 1024
#define WRITE_BUF_SIZEk_m 1024
#define BUF_FLUSHk_m -1

/* for command chaining */
#define CMD_NORMk_m 0
#define CMD_ORk_m 1
#define CMD_ANDk_m 2
#define CMD_CHAINk_m 3

/* for convert_number() */
#define CONVERT_LOWERCASEk_m 1
#define CONVERT_UNSIGNEDk_m 2

/* 1 if using system getline() */
#define USE_GETLINEk_m 0
#define USE_STRTOKk_m 0

#define HIST_FILEk_m ".simple_shell_history"
#define HIST_MAXk_m 4096

extern char **environ;

/**
 * struct liststrk_m - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststrk_m
{
	int num;
	char *str;
	struct liststrk_m *next;
} list_tk_m;

/**
 *struct passinfok_m - contains pseudo-arguements to pass into a function,
 *					allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfok_m
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_tk_m *env;
	list_tk_m *history;
	list_tk_m *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;	  /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_tk_m;

#define INFO_INIT                                                               \
	{                                                                           \
		NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
			0, 0, 0                                                             \
	}

/**
 *struct builtink_m - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtink_m
{
	char *type;
	int (*func)(info_tk_m *);
} builtin_tablek_m;

/* hsh.c */
int hshk_m(info_tk_m *, char **);
int find_builtink_m(info_tk_m *);
void find_cmdk_m(info_tk_m *);
void fork_cmdk_m(info_tk_m *);

/* path.c */
int is_cmdk_m(info_tk_m *, char *);
char *dup_charsk_m(char *, int, int);
char *find_pathk_m(info_tk_m *, char *, char *);

/* loophsh.c */
int loophshk_m(char **);

/* err_string_functions.c */
void _eputsk_m(char *);
int _eputchark_m(char);
int _putfdk_m(char c, int fd);
int _putsfdk_m(char *str, int fd);

/* string_functions.c */
int _strlenk_m(char *);
int _strcmpk_m(char *, char *);
char *starts_withk_m(const char *, const char *);
char *_strcatk_m(char *, char *);

/* string_functions2.c */
char *_strcpyk_m(char *, char *);
char *_strdupk_m(const char *);
void _putsk_m(char *);
int _putchark_m(char);

/* string_functions3.c */
char *_strncpyk_m(char *, char *, int);
char *_strncatk_m(char *, char *, int);
char *_strchrk_m(char *, char);

/* string_functions4.c */
char **strtowk_m(char *, char *);
char **strtow2k_m(char *, char);

/* memory_functions */
char *_memsetk_m(char *, char, unsigned int);
void ffreek_m(char **);
void *_reallock_m(void *, unsigned int, unsigned int);

/* memory_functions2.c */
int bfreek_m(void **);

/* more_functions.c */
int interactivek_m(info_tk_m *);
int is_delimk_m(char, char *);
int _isalphak_m(int);
int _atoik_m(char *);

/* more_functions2.c */
int _erratoik_m(char *);
void print_errork_m(info_tk_m *, char *);
int print_dk_m(int, int);
char *convert_numberk_m(long int, int, int);
void remove_commentsk_m(char *);

/* builtin_emulators.c */
int _myexitk_m(info_tk_m *);
int _mycdk_m(info_tk_m *);
int _myhelpk_m(info_tk_m *);

/* builtin_emulators2.c */
int _myhistoryk_m(info_tk_m *);
int _myaliask_m(info_tk_m *);

/* getline.c module */
ssize_t get_inputk_m(info_tk_m *);
int _getlinek_m(info_tk_m *, char **, size_t *);
void sigintHandlerk_m(int);

/* info.c module */
void clear_infok_m(info_tk_m *);
void set_infok_m(info_tk_m *, char **);
void free_infok_m(info_tk_m *, int);

/* env.c module */
char *_getenvk_m(info_tk_m *, const char *);
int _myenvk_m(info_tk_m *);
int _mysetenvk_m(info_tk_m *);
int _myunsetenvk_m(info_tk_m *);
int populate_env_listk_m(info_tk_m *);

/* env2.c module */
char **get_environk_m(info_tk_m *);
int _unsetenvk_m(info_tk_m *, char *);
int _setenvk_m(info_tk_m *, char *, char *);

/* file_io_functions.c */
char *get_history_filek_m(info_tk_m *info);
int write_historyk_m(info_tk_m *info);
int read_historyk_m(info_tk_m *info);
int build_history_listk_m(info_tk_m *info, char *buf, int linecount);
int renumber_historyk_m(info_tk_m *info);

/* liststr.c module */
list_tk_m *add_nodek_m(list_tk_m **, const char *, int);
list_tk_m *add_node_endk_m(list_tk_m **, const char *, int);
size_t print_list_strk_m(const list_tk_m *);
int delete_node_at_indexk_m(list_tk_m **, unsigned int);
void free_listk_m(list_tk_m **);

/* liststr2.c module */
size_t list_lenk_m(const list_tk_m *);
char **list_to_stringsk_m(list_tk_m *);
size_t print_listk_m(const list_tk_m *);
list_tk_m *node_starts_withk_m(list_tk_m *, char *, char);
ssize_t get_node_indexk_m(list_tk_m *, list_tk_m *);

/* chain.c */
int is_chaink_m(info_tk_m *, char *, size_t *);
void check_chaink_m(info_tk_m *, char *, size_t *, size_t, size_t);
int replace_aliask_m(info_tk_m *);
int replace_varsk_m(info_tk_m *);
int replace_stringk_m(char **, char *);

/*lol*/
ssize_t read_bufk_m(info_tk_m *info, char *buf, size_t *i);
ssize_t input_bufk_m(info_tk_m *info, char **buf, size_t *len);
int unset_aliask_m(info_tk_m *info, char *str);
int set_aliask_m(info_tk_m *info, char *str);
int print_aliask_m(list_tk_m *node);

#endif
