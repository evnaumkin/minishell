/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:05:33 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 04:24:15 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_handle_test(char *str)
{
	int	    ret;
	char	**args;

	//ft_printf("str=%s", str);
	args = ft_split_sep(str, " \t\n");
	//ft_tabprint(args);
	if (args == NULL)
		return (EXIT_FAILURE);
    ret = EXIT_SUCCESS;
	if (ft_strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
			ret = ft_test_cd(args);
		else if (ft_strlen(args[1]) == 0)
			ret = ft_test_cd(args);
		else if (ft_strcmp(args[1], "") == 0)
			ret = ft_test_cd(args);
		else if (ft_strcmp(args[1], " ") == 0)
			ret = ft_test_cd(args);
		else if (ft_strcmp(args[1], "-") == 0)
			ret = ft_test_cd_dash(args);
		// else if (ft_strcmp(args[1], "~") == 0)
		// 	ret = ft_test_cd_tilde(args);
		else if (ft_strlen(args[1]) != 0)
			ret = ft_test_cd_path(args);
	}
	else if (ft_strcmp(args[0], "echo") == 0)
	{
		ret = ft_test_echo(args);
	}
	ft_tabfree(args);
	return (ret);
}
