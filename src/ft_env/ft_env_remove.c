/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 00:34:36 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 00:36:31 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_env_remove(t_env *env, char *key)
{
	t_env *tmp;

	if (env == NULL || key == NULL)
		return (false);
	if (env)
	{
		if (!ft_strcmp(env->key, key))
		{
			tmp = env->next;
			ft_env_del(env, &ft_memdel);
			env = tmp;
			return (true);
		}
	}
	while (env && env->next)
	{
		tmp = env->next->next;
		if (!ft_strcmp(env->next->key, key))
		{
			ft_env_del(env->next, &ft_memdel);
			env->next = tmp;
			return (true);
		}
		env = env->next;
	}
	return (false);
}
