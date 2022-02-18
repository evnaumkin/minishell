/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:40:53 by llornel           #+#    #+#             */
/*   Updated: 2022/02/15 03:38:47 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_shlvl_inc(void)
{
	char	*value;
	int		level;

	value = ft_env_get(g_params.env, "SHLVL");
	if (value == NULL)
		level = 1;
	else if (ft_strlen(value) == 0)
		level = 1;
	else if (!ft_strisdigit(value))
		level = 1;
	else
		level = ft_atoi(value) + 1;
	ft_env_set(g_params.env, "SHLVL", ft_itoa(level));
	ft_memdel(value);
}

int	ft_params_init(char **envp)
{
	int		ret;

	ret = ft_env_init(&g_params.env, envp);
	if (ret != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	g_params.token = NULL;
	g_params.listtok = NULL;
	g_params.pwd = ft_strdup(getcwd(NULL, 0));
	g_params.oldpwd = NULL;
	g_params.heredoc_status = 0;
	g_params.exit_status = 0;
	g_params.sigint = 0;
	g_params.sigquit = 0;
	g_params.pid = 0;
	//ft_env_remove(g_params.env, "OLDPWD");
	ft_shlvl_inc();
	ft_env_set(g_params.env, "OLDPWD", g_params.oldpwd);
	ft_env_set(g_params.env, "PWD", g_params.pwd);
	return (EXIT_SUCCESS);
}
