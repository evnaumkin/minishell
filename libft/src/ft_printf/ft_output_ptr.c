/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:31:27 by llornel           #+#    #+#             */
/*   Updated: 2022/02/06 15:53:07 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_output_prefix(t_data_flag *data_flag)
{
	data_flag->retlen += ft_putstr("0x");
}

static void	ft_print_str(t_data_flag *data_flag, char *str)
{
	if (!data_flag->is_zero)
		data_flag->retlen += ft_putstr(str);
	if (data_flag->is_zero && !data_flag->is_precision)
		data_flag->retlen += ft_putchar('0');
}

static void	ft_output_left(t_data_flag *data_flag, char *str)
{
	if (data_flag->zero)
	{
		ft_output_prefix(data_flag);
		data_flag->retlen += ft_putnchar('0', data_flag->pad_precision);
		data_flag->retlen += ft_putnchar('0', data_flag->pad_width);
		ft_print_str(data_flag, str);
	}
	else
	{
		ft_output_prefix(data_flag);
		data_flag->retlen += ft_putnchar('0', data_flag->pad_precision);
		ft_print_str(data_flag, str);
		data_flag->retlen += ft_putnchar(' ', data_flag->pad_width);
	}
}

static void	ft_output_right(t_data_flag *data_flag, char *str)
{
	if (data_flag->zero)
	{
		ft_output_prefix(data_flag);
		data_flag->retlen += ft_putnchar('0', data_flag->pad_precision);
		data_flag->retlen += ft_putnchar('0', data_flag->pad_width);
		ft_print_str(data_flag, str);
	}
	else
	{
		data_flag->retlen += ft_putnchar(' ', data_flag->pad_width);
		ft_output_prefix(data_flag);
		data_flag->retlen += ft_putnchar('0', data_flag->pad_precision);
		ft_print_str(data_flag, str);
	}
}

void	ft_output_ptr(t_data_flag *data_flag, char *str)
{
	if (data_flag->dash)
		ft_output_left(data_flag, str);
	else
		ft_output_right(data_flag, str);
}
