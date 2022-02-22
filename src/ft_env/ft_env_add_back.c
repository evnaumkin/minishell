/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 00:39:09 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 00:39:17 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_add_back(t_env **env, t_env *new)
{
	t_env	*last;

	if (env == NULL)
		return ;
	if (*env)
	{
		last = ft_env_last(*env);
		last->next = new;
	}
	else
		*env = new;
}
