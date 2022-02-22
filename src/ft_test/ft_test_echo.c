/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 04:14:50 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 04:25:10 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_test_echo(char **args)
{
	int	    ret;

	ret = ft_builtin_echo(args);
    ft_printf(" ret=%d\n", ret);
	ft_putendl_fd(STDOUT, "-------------------");
	return (ret);
}