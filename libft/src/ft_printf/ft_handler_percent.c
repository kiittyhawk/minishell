/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:10:51 by llornel           #+#    #+#             */
/*   Updated: 2022/02/06 16:45:42 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_validate(t_data_flag *data_flag)
{
	if (data_flag->is_width && data_flag->width < 0)
	{
		data_flag->width = -1 * data_flag->width;
		data_flag->dash = 1;
		data_flag->zero = 0;
	}
	if (data_flag->sign == 1)
		data_flag->sign = 0;
	if (data_flag->space)
		data_flag->space = 0;
	if (data_flag->lattice)
		data_flag->lattice = 0;
	if (data_flag->is_precision)
		data_flag->is_precision = 0;
	return (0);
}

static int	ft_compute(t_data_flag *data_flag)
{
	if (data_flag->is_width)
		data_flag->pad_width = data_flag->width - ft_min(data_flag->width, 1);
	else
		data_flag->pad_width = 0;
	return (0);
}

void	ft_handler_percent(t_data_flag *data_flag)
{
	char	c;

	c = '%';
	if (ft_validate(data_flag) == -1)
		return ;
	ft_compute(data_flag);
	ft_output_percent(data_flag, c);
}
