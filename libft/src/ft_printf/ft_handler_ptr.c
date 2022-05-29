/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:10:51 by llornel           #+#    #+#             */
/*   Updated: 2022/02/06 16:45:20 by llornel          ###   ########.fr       */
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
	{
		data_flag->lattice = 0;
		return (-1);
	}	
	if (data_flag->zero && data_flag->dash && data_flag->is_width)
		data_flag->zero = 0;
	return (0);
}

static void	ft_compute(t_data_flag *data_flag, unsigned long ptr)
{
	int		prefix;
	int		ptrlen;
	int		imin;

	ptrlen = ft_nbrlen_base(ptr, 16);
	prefix = 2;
	data_flag->pad_precision = 0;
	data_flag->pad_width = 0;
	if (ptr == 0)
		data_flag->is_zero = 1;
	if (data_flag->is_zero && data_flag->is_precision)
		ptrlen = ft_max(ptrlen - 1, 0);
	if (data_flag->is_precision)
	{	
		imin = ft_min(data_flag->precision, ptrlen);
		data_flag->pad_precision = data_flag->precision - imin;
	}
	if (data_flag->is_width)
	{	
		imin = ft_min(data_flag->width, data_flag->pad_precision
				+ ptrlen + prefix);
		data_flag->pad_width = data_flag->width - imin;
	}
}

void	ft_handler_ptr(t_data_flag *data_flag, va_list args)
{
	unsigned long	ptr;
	char			*sptr;

	ptr = va_arg(args, unsigned long);
	if (ft_validate(data_flag) == -1)
		return ;
	ft_compute(data_flag, ptr);
	sptr = ft_itoa_base(ptr, 16);
	if (sptr == NULL)
		return ;
	ft_output_ptr(data_flag, sptr);
	free(sptr);
}
