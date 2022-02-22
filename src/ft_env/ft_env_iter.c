/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 00:40:49 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 00:40:59 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_iter(t_env *env, void (*f)(t_env *))
{
	if (env == NULL || f == NULL)
		return ;
	while (env)
	{
		(*f)(env);
		env = env->next;
	}
}
