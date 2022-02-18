/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:56:19 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:12:02 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned long	base_len;
	unsigned long	num;
	int				i;

	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	i = 1;
	num = n;
	base_len = ft_strlen(base);
	if (num >= base_len)
	{
		i += ft_putnbr_base(num / base_len, base);
		ft_putchar(base[num % base_len]);
	}
	else if (num < base_len)
		ft_putchar(base[num]);
	return (i);
}
