/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:13:22 by llornel           #+#    #+#             */
/*   Updated: 2022/02/14 18:58:44 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_builtin_exit(char **args)
{
	bool	valid;
	char	*search;

	valid = true;
	search = *(args + 1);
	while (search != NULL && *search)
		if (!ft_isdigit(*search++))
			valid = false;
	if (!valid)
	{
		ft_putstr_fd(STDERR, "exit\nexit: ");
		ft_putstr_fd(STDERR, *(args + 1));
		ft_putendl_fd(STDERR, ": " ERR_MSG_NUMERIC);
		exit(EXIT_RANGE);
	}
	else if (valid && *(args + 1) != NULL && *(args + 2) != NULL)
	{
		ft_putendl_fd(STDERR, "exit\nexit: " ERR_MSG_TOO_MANY_ARGS);
		return (EXIT_FAILURE);
	}
	ft_putendl_fd(STDERR, "exit");
	if (*(args + 1) == NULL)
		exit(EXIT_SUCCESS);
	exit(ft_atoi(*(args + 1)));
}
