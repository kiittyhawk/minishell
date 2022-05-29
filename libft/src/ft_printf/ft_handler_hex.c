/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:10:51 by llornel           #+#    #+#             */
/*   Updated: 2022/02/06 16:45:33 by llornel          ###   ########.fr       */
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
	if (data_flag->zero && data_flag->dash && data_flag->is_width)
		data_flag->zero = 0;
	if (data_flag->is_width && data_flag->precision < 0)
		data_flag->is_precision = 0;
	if (data_flag->zero && data_flag->is_precision)
		data_flag->zero = 0;
	return (0);
}

static void	ft_compute(t_data_flag *data_flag, unsigned int hex)
{
	int		prefix;
	int		hexlen;
	int		imin;

	hexlen = ft_nbrlen_base(hex, 16);
	prefix = 0;
	if ((data_flag->lattice && hex > 0))
		prefix = 2;
	if (hex == 0)
		data_flag->is_zero = 1;
	data_flag->pad_precision = 0;
	data_flag->pad_width = 0;
	if (data_flag->is_precision)
	{	
		imin = ft_min(data_flag->precision, hexlen);
		data_flag->pad_precision = data_flag->precision - imin;
	}
	if (data_flag->is_width)
	{	
		imin = ft_min(data_flag->width, data_flag->pad_precision
				+ hexlen + prefix);
		data_flag->pad_width = data_flag->width - imin;
	}
}

void	ft_handler_hex(t_data_flag *data_flag, va_list args)
{
	unsigned int	hex;
	char			*shex;

	hex = va_arg(args, unsigned int);
	data_flag->type = 'x';
	if (ft_validate(data_flag) == -1)
		return ;
	ft_compute(data_flag, hex);
	shex = ft_itoa_base(hex, 16);
	if (shex == NULL)
		return ;
	ft_output_hex(data_flag, shex);
	free(shex);
}

void	ft_handler_hexx(t_data_flag *data_flag, va_list args)
{
	unsigned int	hex;
	char			*shex;

	hex = va_arg(args, unsigned int);
	data_flag->type = 'X';
	if (ft_validate(data_flag) == -1)
		return ;
	ft_compute(data_flag, hex);
	shex = ft_strtoupper(ft_itoa_base(hex, 16));
	if (shex == NULL)
		return ;
	ft_output_hex(data_flag, shex);
	free(shex);
}
