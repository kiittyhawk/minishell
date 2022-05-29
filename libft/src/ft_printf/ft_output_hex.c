/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:31:27 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 05:19:12 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_str(t_data_flag *data_flag, char *str)
{
	if (!data_flag->is_zero || !data_flag->is_precision
		|| data_flag->precision)
		data_flag->retlen += ft_putstr_fd(data_flag->fd, str);
	else if (data_flag->is_width && data_flag->zero)
		data_flag->retlen += ft_putchar_fd(data_flag->fd, '0');
	else if (data_flag->is_width && data_flag->width)
		data_flag->retlen += ft_putchar_fd(data_flag->fd, ' ');
}

static void	ft_output_prefix(t_data_flag *data_flag)
{
	if (data_flag->lattice && !data_flag->is_zero)
	{
		if (data_flag->type == 'X')
			data_flag->retlen += ft_putstr_fd(data_flag->fd, "0X");
		else
			data_flag->retlen += ft_putstr_fd(data_flag->fd, "0x");
	}
}

static void	ft_output_left(t_data_flag *data_flag, char *str)
{
	if (data_flag->zero)
	{
		ft_output_prefix(data_flag);
		data_flag->retlen += ft_putnchar_fd(data_flag->fd, '0',
				data_flag->pad_precision);
		data_flag->retlen += ft_putnchar_fd(data_flag->fd, '0',
				data_flag->pad_width);
		ft_print_str(data_flag, str);
	}
	else
	{
		ft_output_prefix(data_flag);
		data_flag->retlen += ft_putnchar_fd(data_flag->fd, '0',
				data_flag->pad_precision);
		ft_print_str(data_flag, str);
		data_flag->retlen += ft_putnchar_fd(data_flag->fd, ' ',
				data_flag->pad_width);
	}
}

static void	ft_output_right(t_data_flag *data_flag, char *str)
{
	if (data_flag->zero)
	{
		ft_output_prefix(data_flag);
		data_flag->retlen += ft_putnchar_fd(data_flag->fd, '0',
				data_flag->pad_precision);
		data_flag->retlen += ft_putnchar_fd(data_flag->fd, '0',
				data_flag->pad_width);
		ft_print_str(data_flag, str);
	}
	else
	{
		data_flag->retlen += ft_putnchar_fd(data_flag->fd, ' ',
				data_flag->pad_width);
		ft_output_prefix(data_flag);
		data_flag->retlen += ft_putnchar_fd(data_flag->fd, '0',
				data_flag->pad_precision);
		ft_print_str(data_flag, str);
	}
}

void	ft_output_hex(t_data_flag *data_flag, char *str)
{
	if (data_flag->dash)
		ft_output_left(data_flag, str);
	else
		ft_output_right(data_flag, str);
}
