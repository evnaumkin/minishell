/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:05:33 by llornel           #+#    #+#             */
/*   Updated: 2022/02/16 01:09:58 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_handle_test(char *str)
{
	int	    ret;
	char	**args;

	args = ft_split_sep(str, " \t\n");
	if (args == NULL)
		return (EXIT_FAILURE);
	//ft_tabprint(args);
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
	ft_tabfree(args);
	return (ret);
}
