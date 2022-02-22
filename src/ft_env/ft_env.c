/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:24:09 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 03:26:45 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env_add(t_env **env, char *str)
{
	t_env	*new;
	char	*key;
	char	*value;
    int		ret;

	ret = EXIT_SUCCESS;
	ft_env_parse(str, &key, &value);
	new = ft_env_new(key, value);
	if (new == NULL)
		ret = EXIT_FAILURE;
	if (ret == EXIT_SUCCESS)
		ft_env_add_back(env, new);
	ft_memdel(key);
	ft_memdel(value);
	return (ret);
}

int	ft_env_init(t_env **env, char **envp)
{
	//char	**tab;
    //t_env   **tmp_env;
    int     i;

	// tab = ft_tabdup(envp);
	// if (tab == NULL)
	// 	return (FAILURE);
    i = 0;
    //tmp_env = env;
    while (envp[i])
	{
        ft_env_add(env, envp[i]);
        i++;
    }
	//ft_tabfree(tab);
	return (EXIT_SUCCESS);
}
