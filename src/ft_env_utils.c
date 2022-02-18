/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:05:51 by llornel           #+#    #+#             */
/*   Updated: 2022/02/13 12:02:48 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_env_ischar(int c)
{
	if (ft_isalnum(c) || c == '_')
		return (true);
	return (false);
}

int	ft_env_isvalid(const char *str)
{
	int		i;

	i = 0;
	if (ft_isdigit(str[i]) == 1)
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (ft_isalnum(str[i]) == 0)
			return (-1);
		i++;
	}
	if (str[i] != '=')
		return (2);
	return (1);
}

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

void	ft_str_print(char *str)
{
	if (str == NULL)
		return ;
	ft_putstr("declare -x ");
	ft_putstr(str);
	ft_putstr("\n");
}
