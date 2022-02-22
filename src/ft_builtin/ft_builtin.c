/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:22:58 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 11:11:31 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_is_builtin(char *str)
{
	if (ft_strcmp(str, "echo") == 0)
		return (true);
	if (ft_strcmp(str, "cd") == 0)
		return (true);
	if (ft_strcmp(str, "pwd") == 0)
		return (true);
	if (ft_strcmp(str, "env") == 0)
		return (true);
	if (ft_strcmp(str, "export") == 0)
		return (true);
	if (ft_strcmp(str, "unset") == 0)
		return (true);
	if (ft_strcmp(str, "exit") == 0)
		return (true);
	return (false);
}

int		ft_exec_builtin(char **args)
{
	int ret;

	ret = 0;
	if (ft_strcmp(args[0], "echo") == 0)
		ret = ft_builtin_echo(args);
	if (ft_strcmp(args[0], "cd") == 0)
		ret = ft_builtin_cd(args, g_params.env);
	if (ft_strcmp(args[0], "pwd") == 0)
		ret = ft_builtin_pwd();
	if (ft_strcmp(args[0], "export") == 0)
		ret = ft_builtin_export(args, g_params.env);
	if (ft_strcmp(args[0], "unset") == 0)
		ret = ft_builtin_unset(args, g_params.env);
	if (ft_strcmp(args[0], "env") == 0)
		ret = ft_builtin_env(g_params.env);
	if (ft_strcmp(args[0], "exit") == 0)
		ret = ft_builtin_exit(args);
	return (ret);
}
