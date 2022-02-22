/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 00:36:54 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 00:48:23 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_env_get(t_env *env, char *key)
{
	t_env 	*tmp;
	char 	*value;

	if (env == NULL || key == NULL)
		return (false);
	tmp = ft_env_find(env, key);
	if (tmp == NULL || tmp->value == NULL)
		return (false);
	value = ft_strdup(tmp->value);
	if (value == NULL)
		return (NULL);
	return (value);
}
