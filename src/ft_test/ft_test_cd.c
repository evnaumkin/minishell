/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:00:44 by llornel           #+#    #+#             */
/*   Updated: 2022/02/16 01:12:00 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_test_cd(char **args)
{
	int	    ret;

	ft_env_remove(g_params.env, "HOME");
	ret = ft_builtin_cd(args, g_params.env);
    ft_printf("ret=%d\n", ret);
	ft_putendl_fd(STDOUT, "-------------------");
	ft_env_set(g_params.env, "HOME", NULL);
	ret = ft_builtin_cd(args, g_params.env);
    ft_printf("ret=%d\n", ret);
	ft_putendl_fd(STDOUT, "-------------------");
	ft_env_set(g_params.env, "HOME", "");
	ret = ft_builtin_cd(args, g_params.env);
    ft_printf("ret=%d\n", ret);
	ft_putendl_fd(STDOUT, "-------------------");
	ft_env_set(g_params.env, "HOME", "		   ");
	ret = ft_builtin_cd(args, g_params.env);
    ft_printf("ret=%d\n", ret);
	ft_putendl_fd(STDOUT, "-------------------");
	ft_env_set(g_params.env, "HOME", " /del /1/ ");
	ret = ft_builtin_cd(args, g_params.env);
    ft_printf("ret=%d\n", ret);
	ft_putendl_fd(STDOUT, "-------------------");
	ft_env_set(g_params.env, "HOME", "/Users/imac/Documents/42cursus/Develop/minishell");
	ret = ft_builtin_cd(args, g_params.env);
    ft_printf("ret=%d\n", ret);
	ft_putendl_fd(STDOUT, "-------------------");
	return (ret);
}

int	ft_test_cd_dash(char **args)
{
	int	    ret;

	ft_env_remove(g_params.env, "OLDPWD");
	ret = ft_builtin_cd(args, g_params.env);
    ft_printf("ret=%d\n", ret);
	ft_putendl_fd(STDOUT, "-------------------");
	ft_env_set(g_params.env, "OLDPWD", NULL);
	ret = ft_builtin_cd(args, g_params.env);
    ft_printf("ret=%d\n", ret);
	ft_putendl_fd(STDOUT, "-------------------");
	ft_env_set(g_params.env, "OLDPWD", "");
	ret = ft_builtin_cd(args, g_params.env);
    ft_printf("ret=%d\n", ret);
	ft_putendl_fd(STDOUT, "-------------------");
	ft_env_set(g_params.env, "OLDPWD", "		   ");
	ret = ft_builtin_cd(args, g_params.env);
    ft_printf("ret=%d\n", ret);
	ft_putendl_fd(STDOUT, "-------------------");
	ft_env_set(g_params.env, "OLDPWD", " /del /1/ ");
	ret = ft_builtin_cd(args, g_params.env);
    ft_printf("ret=%d\n", ret);
	ft_putendl_fd(STDOUT, "-------------------");
	ft_env_set(g_params.env, "OLDPWD", "/Users/imac/Documents/42cursus/Develop/minishell");
	ret = ft_builtin_cd(args, g_params.env);
    ft_printf("ret=%d\n", ret);
	ft_putendl_fd(STDOUT, "-------------------");
	return (ret);
}

int	ft_test_cd_path(char **args)
{
	int	    ret;

	ft_env_remove(g_params.env, "OLDPWD");
	ret = ft_builtin_cd(args, g_params.env);
    ft_printf("ret=%d\n", ret);
	ft_putendl_fd(STDOUT, "-------------------");
	ft_env_set(g_params.env, "OLDPWD", NULL);
	ret = ft_builtin_cd(args, g_params.env);
    ft_printf("ret=%d\n", ret);
	ft_putendl_fd(STDOUT, "-------------------");
	ft_env_set(g_params.env, "OLDPWD", "");
	ret = ft_builtin_cd(args, g_params.env);
    ft_printf("ret=%d\n", ret);
	ft_putendl_fd(STDOUT, "-------------------");
	ft_env_set(g_params.env, "OLDPWD", "		   ");
	ret = ft_builtin_cd(args, g_params.env);
    ft_printf("ret=%d\n", ret);
	ft_putendl_fd(STDOUT, "-------------------");
	ft_env_set(g_params.env, "OLDPWD", " /del /1/ ");
	ret = ft_builtin_cd(args, g_params.env);
    ft_printf("ret=%d\n", ret);
	ft_putendl_fd(STDOUT, "-------------------");
	ft_env_set(g_params.env, "OLDPWD", "/Users/imac/Documents/42cursus/Develop/minishell");
	ret = ft_builtin_cd(args, g_params.env);
    ft_printf("ret=%d\n", ret);
	ft_putendl_fd(STDOUT, "-------------------");
	return (ret);
}
