/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:47:42 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:12:06 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(int fd, char *str)
{
	if (str == NULL)
		return ;
	write(fd, str, ft_strlen(str));
}

int	ft_putstr(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = ft_strlen(str);
	ft_putstr_fd(STDOUT, str);
	return (i);
}
