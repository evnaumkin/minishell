/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:02:00 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 11:05:20 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isoverflow(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

long	ft_atol(const char *str)
{
	int						i;
	int						sign;
	unsigned long long int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_isplusminus(str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (num >= MAX_LL_INT)
		{
			num = ft_isoverflow(sign);
			break ;
		}
		num = num * 10 + (str[i++] - '0');
	}
	return (num * sign);
}