/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_add_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 00:38:38 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 00:38:48 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_add_front(t_env **env, t_env *new)
{
	if (*env == NULL)
	{
		*env = new;
		return ;
	}
	if (new == NULL)
		return ;
	new->next = *env;
	*env = new;
}
