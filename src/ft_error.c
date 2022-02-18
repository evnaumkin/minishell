/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:54:34 by llornel           #+#    #+#             */
/*   Updated: 2022/02/14 23:01:00 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_perror(char *str)
{
	if (str)
		ft_putendl_fd(STDERR, str);
	exit (EXIT_FAILURE);
}

int	ft_catch_error(int ret, char *str)
{
	if (ret == -1)
		ft_perror(str);
	return (ret);
}

int	ft_exit_error(void *ptr, int ret)
{
	rl_clear_history();
	ft_memdel(ptr);
	ft_env_clear(&g_params.env, &ft_memdel);
	return (ret);
}

void	ft_fail(char *str)
{
	ft_putstr_fd(STDERR, "error: ");
	if (str == NULL)
		ft_putendl_fd(STDERR, strerror(errno));
	else
	{
		if (errno)
		{
			ft_putstr_fd(STDERR, str);
			ft_putendl_fd(STDERR, strerror(errno));
		}
		else
			ft_putendl_fd(STDERR, str);
	}
	exit(EXIT_FAILURE);
}

int	ft_get_errcode(void)
{
	return (0);
}

int	ft_exit_output(char **args)
{
	int		ret;
	int		i;

	i = 0;
	if (ft_strncmp(args[i], "exit", ft_strlen(args[i])) != 0)
		return (EXIT_FAILURE);
	i++;
	if (args[i])
		ret = ft_atoi(args[i]);
	else
		ret = ft_get_errcode();
	ft_putendl_fd(STDERR, "exit\n");
	return (ret);
}

int	ft_exit_ctrld(void *ptr, int ret)
{
	char	**args;

	if (ret == EXIT_CTRL_D)
	{
		args = ft_calloc(3, sizeof(*args));
		args[0] = ft_strdup("exit");
		args[1] = ft_itoa(ft_get_errcode());
		ft_exit_output(args);
		ft_tabfree(args);
	}
	ft_exit_error(ptr, ret);
	return (ret);
}

int	ft_handle_error(int ret)
{
	if (ret == ERR_CODE_NUMBER_AGRS)
		ft_putendl_fd(STDERR, ERR_MSG_NUMBER_AGRS);
	else if (ret == ERR_CODE_INVALID_AGRS)
		ft_putendl_fd(STDERR, ERR_MSG_INVALID_AGRS);
	else if (ret == ERR_CODE_VALUE_AGRS)
		ft_putendl_fd(STDERR, ERR_MSG_VALUE_AGRS);
	else if (ret == ERR_CODE_MALLOC)
		ft_putendl_fd(STDERR, ERR_MSG_MALLOC);
	else
		ft_putendl_fd(STDERR, ERR_MSG_UNDEFINED);
	return (ret);
}
