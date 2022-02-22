/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:07:18 by llornel           #+#    #+#             */
/*   Updated: 2022/02/14 23:01:18 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unlink(char *filename)
{
	if (unlink(filename) == -1)
	{
		ft_putendl_fd(STDERR, ERR_MSG_CANNOT_DELETE);
		exit(EXIT_FAILURE);
	}
}

int	ft_openinfile(char *filename, int flags)
{
	if (access(filename, F_OK) == -1)
	{
		ft_putstr_fd(STDERR, filename);
		ft_putendl_fd(STDERR, ERR_MSG_NO_FILE_OR_DIR);
		exit(EXIT_FAILURE);
	}
	else if (access(filename, R_OK) == -1)
	{
		ft_putstr_fd(STDERR, filename);
		ft_putendl_fd(STDERR, ERR_MSG_PERMISSION_DENIED);
		exit(EXIT_FAILURE);
	}
	return (open(filename, flags));
}

int	ft_openoutfile(char *filename, int flags)
{
	if (access(filename, F_OK) != -1 && access(filename, W_OK) == -1)
	{
		ft_putstr_fd(STDERR, filename);
		ft_putendl_fd(STDERR, ERR_MSG_PERMISSION_DENIED);
		exit(EXIT_FAILURE);
	}
	return (open(filename, flags));
}
