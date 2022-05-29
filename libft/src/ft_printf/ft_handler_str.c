/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:10:51 by llornel           #+#    #+#             */
/*   Updated: 2022/02/06 16:44:55 by llornel          ###   ########.fr       */
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
		return (-1);
	if (data_flag->space)
	{
		data_flag->space = 0;
		return (-1);
	}	
	if (data_flag->lattice)
	{
		data_flag->lattice = 0;
		return (-1);
	}	
	if (data_flag->zero)
	{
		data_flag->zero = 0;
		return (-1);
	}	
	return (0);
}

static void	ft_compute(t_data_flag *data_flag, char *str)
{
	int	slen;

	if (data_flag->width < 0)
	{
		data_flag->is_width = 0;
		data_flag->width = 0;
	}	
	if (data_flag->precision < 0)
	{
		data_flag->is_precision = 0;
		data_flag->precision = 0;
	}
	if (!data_flag->is_width)
		return ;
	if (data_flag->is_precision)
		slen = ft_min(data_flag->precision, ft_strlen(str));
	else
		slen = ft_strlen(str);
	data_flag->pad_width = data_flag->width - ft_min(data_flag->width, slen);
}

void	ft_handler_str(t_data_flag *data_flag, va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	str = ft_strdup(str);
	if (str == NULL)
		return ;
	if (ft_validate(data_flag) == -1)
		return ;
	ft_compute(data_flag, str);
	ft_output_str(data_flag, str);
	free(str);
}
