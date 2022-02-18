/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:24:09 by llornel           #+#    #+#             */
/*   Updated: 2022/02/14 23:00:40 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_env_add(t_env **env, char *str)
{
	char	*tmp;
	t_env	*new;
	char	*key;
	char	*value;

	tmp = ft_strchr(str, '=');
	if (tmp == NULL)
		return (EXIT_FAILURE);
	key = ft_substr(str, 0, tmp - str);
	value = ft_strdup(tmp + 1);
	new = ft_env_new(key, value);
	if (new == NULL)
		return (EXIT_FAILURE);
	ft_env_add_back(env, new);
	return (EXIT_SUCCESS);
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

char	**ft_env_to_tab(t_env *env)
{
	char	**tab;
	char	*str;
	int		size;
	int		i;

	tab = (char **)malloc(sizeof(char *) * (ft_env_size(env) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (env)
	{
		size = ft_strlen(env->key) + ft_strlen(env->value);
		str = (char *)malloc(sizeof(char) * (size + 4));
		if (str == NULL)
			return (NULL);
		ft_strncpy(str, env->key, size);
		ft_strncat(str, "=\"", size);
		ft_strncat(str, env->value, size);
		ft_strncat(str, "\"", size);
		tab[i] = str;
		env = env->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
