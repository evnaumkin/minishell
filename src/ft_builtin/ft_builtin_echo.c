/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:37:09 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 04:31:00 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_valid_option(char *str)
{
	int		i;

	if (str[0] != '-')
		return (false);
	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

int	ft_output_echo(char **args)
{
 	int		i;
 	int		exists_option;

	i =	0;
 	exists_option = 0;
	while (args[i] && ft_valid_option(args[i]))
	{
		exists_option = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr(args[i]);
		if (args[i + 1] != NULL)
			ft_putchar(' ');
		i++;
	}
	if (exists_option == 0)
		ft_putchar('\n');
	return (EXIT_SUCCESS);
}

int		ft_builtin_echo(char **args)
{
	int		ret;

	if (args == NULL)
		return (EXIT_FAILURE);
	if (args[0] && !ft_strnstr(args[0], "echo", ft_strlen("echo")))
		return (EXIT_FAILURE);
	if (args[1] == NULL)
	{
		ft_putendl("");
		return (EXIT_SUCCESS);
	}
	ret = ft_output_echo(args + 1);
	return (ret);
}
