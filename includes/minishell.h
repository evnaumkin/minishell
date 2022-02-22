/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:23:08 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 14:00:56 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include <signal.h>
# include <dirent.h>
# include <errno.h>
# include <string.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# include <const.h>

typedef struct s_toktree
{
	int					type;
	char				*data;
	struct s_toktree	*left;
	struct s_toktree	*right;
}	t_toktree;

typedef struct s_token
{
	int				type;
	char			*data;
	struct s_token	*prev;
	struct s_token	*next;
}				t_token;

// typedef struct s_token
// {
// 	int				type;
// 	char			*data;
// }				t_token;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}				t_env;

typedef struct s_params
{
	t_env			*env;
	t_token			*token;
	t_list			*listtok;
	int				fd[2];
	int				pipefd[2];
	int				sigint;
	int				sigquit;
	int				exit_status;
	int				heredoc_status;
	char			*pwd;
	char			*oldpwd;
	pid_t			pid;
}				t_params;

extern t_params	g_params;

void		ft_fail(char *str);
void		ft_perror(char *str);
int			ft_handle_error(int ret);
int			ft_get_errcode(void);
void		ft_set_errcode(int ret);
int			ft_exit_error(void *ptr, int ret);
int			ft_syntax_error(int ret, char *str);

int			ft_env_size(t_env *env);
t_env		*ft_env_new(char *key, char *value);
t_env		*ft_env_last(t_env *env);
t_env		*ft_env_find(t_env *env, char *key);
void		ft_env_add_front(t_env **env, t_env *new);
void		ft_env_add_back(t_env **env, t_env *new);
void		ft_env_del(t_env *env, void (*del)(void*));
void		ft_env_clear(t_env **env, void (*del)(void*));
void		ft_env_iter(t_env *env, void (*f)(t_env *));
void		ft_env_print(t_env *env);
bool		ft_env_remove(t_env *env, char *key);
int			ft_env_add(t_env **env, char *str);
char 		*ft_env_get(t_env *env, char *key);
bool		ft_env_set(t_env *env, char *key, char *value);
void		ft_env_sort_print(t_env	*env);
bool		ft_env_key_isvalid(const char *str);
void		ft_env_parse(char *str, char **key, char **value);
char		**ft_env_to_tab(t_env *env);

char		**ft_get_args(const char *cmd);
char		*ft_get_path(char **env, char *cmd);

int			ft_params_init(char **envp);
int			ft_env_init(t_env **env, char **envp);

void		ft_handler_sigint(int sig);
void		ft_set_signal(int sig, void (*cmd)(int));
void		ft_signal_init(void);
void		ft_echoctl_off(void);

void		ft_free_set(void **dst, void *src);
void		ft_free(void);

bool		ft_check_quotes(char *str);



int			ft_lexer(char *str);
void		ft_execute(char *cmd, char **envp);

int			ft_minishell(int argc, char **argv, char **envp);

/*
** =============================================================================
** Builtin Functions
** =============================================================================
*/

bool		ft_is_builtin(char *str);
int			ft_exec_builtin(char **args);
int			ft_builtin_echo(char **args);
int			ft_builtin_cd(char **args, t_env *env);
int			ft_builtin_pwd(void);
int			ft_builtin_export(char **args, t_env *env);
int			ft_builtin_unset(char **args, t_env *env);
int			ft_builtin_env(t_env *env);
int			ft_builtin_exit(char **args);

/*
** =============================================================================
** Test Functions
** =============================================================================
*/
int			ft_handle_test(char *str);

int			ft_test_cd(char **args);
int			ft_test_cd_dash(char **args);
int			ft_test_cd_tilde(char **args);
int			ft_test_cd_path(char **args);

int			ft_test_echo(char **args);

#endif
