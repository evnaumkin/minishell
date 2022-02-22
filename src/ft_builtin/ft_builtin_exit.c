/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:13:22 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 12:18:11 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_builtin_exit(char **args)
{
	if (args == NULL)
		return (EXIT_FAILURE);
	if (args[0] && !ft_strnstr(args[0], "exit", ft_strlen("exit")))
		return (EXIT_FAILURE);
	if (args[1] == NULL)
		exit(g_params.exit_status);
	//ft_fprintf(STDERR, "args[1] = %s\n", args[1]);
	if (!ft_strisnumber(args[1]))
	{
		ft_fprintf(STDERR, "exit\n%s exit: %s\n", ERR_PROMPT, ERR_MSG_NUMERIC);
		exit(EXIT_RANGE);
	}
	if (ft_tabsize(args) > 2)
	{
		ft_fprintf(STDERR, "exit\n%s exit: %s\n", ERR_PROMPT, ERR_MSG_TOO_MANY_ARGS);
		ft_set_errcode(EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	ft_fprintf(STDERR, "exit\n");
	//ft_fprintf(STDERR, "ft_atoi=%d\n", ft_atoi(args[1]));
	//printf("ft_atol=%ld\n", ft_atol(args[1]));
	exit(ft_atol(args[1]));
}
