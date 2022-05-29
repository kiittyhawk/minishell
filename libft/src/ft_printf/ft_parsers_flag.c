/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsers_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:44:34 by llornel           #+#    #+#             */
/*   Updated: 2022/02/06 14:29:43 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_space(t_data_flag *data_flag)
{
	data_flag->pos++;
	data_flag->space = 1;
	if (data_flag->sign != 0)
		data_flag->space = 0;
}

void	ft_parse_lattice(t_data_flag *data_flag)
{
	data_flag->pos++;
	data_flag->lattice = 1;
}

void	ft_parse_plus(t_data_flag *data_flag)
{
	data_flag->pos++;
	data_flag->sign = 1;
	data_flag->space = 0;
}

void	ft_parse_zero(t_data_flag *data_flag)
{
	data_flag->pos++;
	data_flag->zero = 1;
	if (data_flag->dash == 1)
		data_flag->zero = 0;
}

void	ft_parse_dash(t_data_flag *data_flag)
{
	data_flag->pos++;
	data_flag->dash = 1;
	data_flag->zero = 0;
}
