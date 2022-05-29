/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 14:04:38 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 05:15:13 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_output_char(t_data_flag *data_flag, char c)
{
	if (data_flag->dash)
	{
		data_flag->retlen += ft_putchar_fd(data_flag->fd, c);
		data_flag->retlen += ft_putnchar_fd(data_flag->fd, ' ',
				data_flag->pad_width);
	}
	else
	{
		data_flag->retlen += ft_putnchar_fd(data_flag->fd, ' ',
				data_flag->pad_width);
		data_flag->retlen += ft_putchar_fd(data_flag->fd, c);
	}
}
