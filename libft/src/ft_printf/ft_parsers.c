/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:55:29 by llornel           #+#    #+#             */
/*   Updated: 2022/02/06 14:29:46 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parse_width(char *str, t_data_flag *data_flag, va_list args)
{
	if (str[data_flag->pos] == '*')
	{
		data_flag->is_width = 1;
		data_flag->width = va_arg(args, int);
		data_flag->pos++;
	}
	else if (ft_isdigit(str[data_flag->pos]))
	{
		data_flag->is_width = 1;
		data_flag->width = ft_atoi(&str[data_flag->pos]);
		while (ft_isdigit(str[data_flag->pos]))
			data_flag->pos++;
	}
}

static void	ft_parse_precision(char *str, t_data_flag *data_flag, va_list args)
{
	if (str[data_flag->pos] != '.')
		return ;
	data_flag->is_precision = 1;
	data_flag->pos++;
	if (str[data_flag->pos] == '*')
	{
		data_flag->precision = va_arg(args, int);
		data_flag->pos++;
	}
	else if (ft_isdigit(str[data_flag->pos]))
	{
		data_flag->precision = ft_atoi(&str[data_flag->pos]);
		while (ft_isdigit(str[data_flag->pos]))
			data_flag->pos++;
	}
	else
	{
		data_flag->precision = 0;
	}
}

static void	ft_parse_type(char *str, t_data_flag *data_flag, va_list args)
{
	if (str[data_flag->pos] == 'c')
		ft_handler_char(data_flag, args);
	else if (str[data_flag->pos] == 's')
		ft_handler_str(data_flag, args);
	else if (str[data_flag->pos] == 'p')
		ft_handler_ptr(data_flag, args);
	else if (str[data_flag->pos] == 'd' || str[data_flag->pos] == 'i')
		ft_handler_int(data_flag, args);
	else if (str[data_flag->pos] == 'u')
		ft_handler_uint(data_flag, args);
	else if (str[data_flag->pos] == 'x')
		ft_handler_hex(data_flag, args);
	else if (str[data_flag->pos] == 'X')
		ft_handler_hexx(data_flag, args);
	else if (str[data_flag->pos] == '%')
		ft_handler_percent(data_flag);
}

void	ft_parse_str(char *str, t_data_flag *data_flag, va_list args)
{
	while (!(ft_isalpha(str[data_flag->pos]) || str[data_flag->pos] == '%'))
	{
		if (str[data_flag->pos] == '-')
			ft_parse_dash(data_flag);
		else if (str[data_flag->pos] == '+')
			ft_parse_plus(data_flag);
		else if (str[data_flag->pos] == ' ')
			ft_parse_space(data_flag);
		else if (str[data_flag->pos] == '#')
			ft_parse_lattice(data_flag);
		else if (str[data_flag->pos] == '0')
			ft_parse_zero(data_flag);
		else if (str[data_flag->pos] == '*')
			ft_parse_width(str, data_flag, args);
		else if (str[data_flag->pos] == '.')
			ft_parse_precision(str, data_flag, args);
		else if (ft_isdigit(str[data_flag->pos]))
			ft_parse_width(str, data_flag, args);
		else
			data_flag->pos++;
	}
	ft_parse_type(str, data_flag, args);
}
