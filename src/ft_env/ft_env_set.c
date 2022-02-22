/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 00:37:50 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 03:01:53 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_env_set(t_env *env, char *key, char *value)
{
	t_env 	*tmp;
	t_env	*new;
	char 	*tmp_value;

	if (env == NULL || key == NULL)
		return (false);
	tmp = ft_env_find(env, key);
	if (tmp)
	{
		if (value != NULL)
		{
			//ft_free_set((void **)&tmp->value, value);
			tmp_value = tmp->value;
			tmp->value = ft_strdup(value);
			ft_memdel(tmp_value);
		}
		return (true);
	}
	else
	{
		new = ft_env_new(key, value);
		if (new == NULL)
			return (false);
		ft_env_add_back(&env, new);
		return (true);
	}
	return (false);
}
