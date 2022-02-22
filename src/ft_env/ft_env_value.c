/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 00:42:48 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 03:26:02 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env_value_size(const char *str)
{
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	i++;
	while (str[i])
	{
		size++;
		i++;
	}
	return (size);
}

char	*ft_env_value(char *str)
{
	int		i;
	int		j;
	int		size;
	char	*value;

	size = ft_env_value_size(str);
	value = (char *)malloc(sizeof(char) * (size + 1));
	if (value == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	i++;
	j = 0;
	while (str[i])
	{
		value[j] = str[i];
		i++;
		j++;
	}
	value[j] = '\0';
	return (value);
}
