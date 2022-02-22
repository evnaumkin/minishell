/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 00:33:25 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 00:33:45 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_env_last(t_env *env)
{
	while (env)
	{
		if (env->next == NULL)
			break ;
		env = env->next;
	}
	return (env);
}
