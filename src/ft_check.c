/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 05:45:11 by llornel           #+#    #+#             */
/*   Updated: 2022/02/13 01:15:59 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_check_quotes(char *str)
{
	char *tmp;
	int	i;

	i = 0;
    tmp = str;
	while (*tmp)
	{
		if (*tmp == '\"')
			tmp = ft_strchr(tmp + 1, '\"');
		if (tmp == NULL)
			return (false);
		if (*tmp == '\'')
			tmp = ft_strchr(tmp + 1, '\'');
		if (tmp == NULL)
			return (false);
		i++;
	}
	return (true);
}
