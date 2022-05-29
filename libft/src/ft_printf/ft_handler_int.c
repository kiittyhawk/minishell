/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:10:51 by llornel           #+#    #+#             */
/*   Updated: 2022/02/06 16:43:55 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_validate(t_data_flag *data_flag, int nbr)
{
	if (nbr < 0)
		data_flag->sign = -1;
	if (data_flag->is_width && data_flag->width < 0)
	{
		data_flag->width = -1 * data_flag->width;
		data_flag->dash = 1;
		data_flag->zero = 0;
	}
	if (data_flag->sign != 0 && data_flag->space)
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

static void	ft_compute(t_data_flag *data_flag, long nbr)
{
	int		nbrlen;
	int		sign;
	int		imin;

	if (nbr == 0)
	{
		data_flag->is_zero = 1;
	}
	if (nbr)
		nbrlen = ft_nbrlen(nbr);
	else
		nbrlen = (!data_flag->is_precision || data_flag->precision);
	sign = (nbr < 0 || data_flag->space || data_flag->sign != 0);
	if (data_flag->is_precision)
	{	
		imin = ft_min(data_flag->precision, nbrlen);
		data_flag->pad_precision = data_flag->precision - imin;
	}
	if (data_flag->is_width)
	{	
		imin = ft_min(data_flag->width, data_flag->pad_precision
				+ nbrlen + sign);
		data_flag->pad_width = data_flag->width - imin;
	}
}

void	ft_handler_int(t_data_flag *data_flag, va_list args)
{
	long	nbr;
	char	*snbr;

	nbr = va_arg(args, int);
	if (ft_validate(data_flag, nbr) == -1)
		return ;
	else if (nbr < 0)
		nbr *= -1;
	ft_compute(data_flag, nbr);
	if (nbr == 2147483648)
		snbr = ft_strdup("2147483648");
	else
		snbr = ft_itoa(nbr);
	if (snbr == NULL)
		return ;
	ft_output_int(data_flag, snbr);
	free(snbr);
}
