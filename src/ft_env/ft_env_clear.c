/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 00:40:15 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 00:40:29 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_clear(t_env **env, void (*del)(void*))
{
	t_env	*next;

	if (env == NULL || del == NULL)
		return ;
	while (*env)
	{
		next = (*env)->next;
		ft_env_del(*env, del);
		*env = next;
	}
}
