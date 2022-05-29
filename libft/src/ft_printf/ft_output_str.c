/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 14:31:51 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 05:18:17 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_strsize(t_data_flag *data_flag, int strlen)
{
	if ((data_flag->is_precision) && (data_flag->precision < strlen))
		return (data_flag->precision);
	else
		return (strlen);
}

void	ft_output_str(t_data_flag *data_flag, char *str)
{
	int	strsize;
	int	i;

	strsize = get_strsize(data_flag, ft_strlen(str));
	if (data_flag->dash)
	{
		i = 0;
		while (i < strsize)
			data_flag->retlen += ft_putchar_fd(data_flag->fd, str[i++]);
		data_flag->retlen += ft_putnchar_fd(data_flag->fd, ' ',
				data_flag->pad_width);
	}
	else
	{
		data_flag->retlen += ft_putnchar_fd(data_flag->fd, ' ',
				data_flag->pad_width);
		i = 0;
		while (i < strsize)
			data_flag->retlen += ft_putchar_fd(data_flag->fd, str[i++]);
	}
}
