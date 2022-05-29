/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:31:27 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 05:17:11 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_str(t_data_flag *data_flag, char *str)
{
	if (!data_flag->is_zero)
		data_flag->retlen += ft_putstr_fd(data_flag->fd, str);
	else if (!data_flag->is_precision || data_flag->precision)
		data_flag->retlen += ft_putchar_fd(data_flag->fd, '0');
}

static void	ft_output_sign(t_data_flag *data_flag)
{
	if (data_flag->space)
		data_flag->retlen += ft_putchar_fd(data_flag->fd, ' ');
	else if (data_flag->sign == -1)
		data_flag->retlen += ft_putchar_fd(data_flag->fd, '-');
	else if (data_flag->sign == 1)
		data_flag->retlen += ft_putchar_fd(data_flag->fd, '+');
}

static void	ft_output_left(t_data_flag *data_flag, char *str)
{
	if (data_flag->zero)
	{
		ft_output_sign(data_flag);
		data_flag->retlen += ft_putnchar_fd(data_flag->fd, '0',
				data_flag->pad_precision);
		data_flag->retlen += ft_putnchar_fd(data_flag->fd, '0',
				data_flag->pad_width);
		ft_print_str(data_flag, str);
	}
	else
	{
		ft_output_sign(data_flag);
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
		ft_output_sign(data_flag);
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
		ft_output_sign(data_flag);
		data_flag->retlen += ft_putnchar_fd(data_flag->fd, '0',
				data_flag->pad_precision);
		ft_print_str(data_flag, str);
	}
}

void	ft_output_int(t_data_flag *data_flag, char *str)
{
	if (data_flag->dash)
		ft_output_left(data_flag, str);
	else
		ft_output_right(data_flag, str);
}
