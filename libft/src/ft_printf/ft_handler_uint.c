/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:10:51 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 05:15:27 by llornel          ###   ########.fr       */
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
	if (data_flag->sign != 0)
		data_flag->sign = 0;
	if (data_flag->space)
		data_flag->space = 0;
	if (data_flag->lattice)
	{
		data_flag->lattice = 0;
		return (-1);
	}
	if (data_flag->zero && data_flag->dash && data_flag->is_width)
		data_flag->zero = 0;
	if (data_flag->is_width && data_flag->precision < 0)
		data_flag->is_precision = 0;
	if (data_flag->zero && data_flag->is_precision)
		data_flag->zero = 0;
	return (0);
}

static void	ft_compute(t_data_flag *data_flag, unsigned int nbr)
{
	int		nbrlen;
	int		imin;

	nbrlen = ft_nbrlen_base(nbr, 10);
	data_flag->pad_precision = 0;
	data_flag->pad_width = 0;
	if (nbr == 0)
		data_flag->is_zero = 1;
	if (data_flag->is_precision)
	{
		imin = ft_min(data_flag->precision, nbrlen);
		data_flag->pad_precision = data_flag->precision - imin;
	}
	if (data_flag->is_width)
	{
		imin = ft_min(data_flag->width, data_flag->pad_precision + nbrlen);
		data_flag->pad_width = data_flag->width - imin;
	}
}

void	ft_handler_uint(t_data_flag *data_flag, va_list args)
{
	unsigned int	nbr;
	char			*snbr;

	nbr = va_arg(args, unsigned int);
	if (ft_validate(data_flag) == -1)
		return ;
	ft_compute(data_flag, nbr);
	snbr = ft_uitoa(nbr);
	if (snbr == NULL)
		return ;
	ft_output_uint(data_flag, snbr);
	free(snbr);
}
