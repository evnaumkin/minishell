/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 14:04:38 by llornel           #+#    #+#             */
/*   Updated: 2022/02/06 14:29:28 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_output_left(t_data_flag *data_flag, char c)
{
	if (data_flag->zero)
	{
		data_flag->retlen += ft_putchar(c);
		data_flag->retlen += ft_putnchar('0', data_flag->pad_width);
	}
	else
	{
		data_flag->retlen += ft_putchar(c);
		data_flag->retlen += ft_putnchar(' ', data_flag->pad_width);
	}
}

static void	ft_output_right(t_data_flag *data_flag, char c)
{
	if (data_flag->zero)
	{
		data_flag->retlen += ft_putnchar('0', data_flag->pad_width);
		data_flag->retlen += ft_putchar(c);
	}
	else
	{
		data_flag->retlen += ft_putnchar(' ', data_flag->pad_width);
		data_flag->retlen += ft_putchar(c);
	}
}

void	ft_output_percent(t_data_flag *data_flag, char c)
{
	if (data_flag->dash)
		ft_output_left(data_flag, c);
	else
		ft_output_right(data_flag, c);
}
