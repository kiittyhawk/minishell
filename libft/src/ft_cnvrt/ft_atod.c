/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:21:41 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:10:15 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_atod_parse(const char *str, int i, int sign)
{
	int		decimals;
	double	num;

	decimals = 0;
	num = 0;
	if (!ft_isdigit(str[i]) && str[i] != '.')
		return (num);
	while (str[i] && ft_isdigit(str[i]))
		num = num * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	if (!ft_isdigit(str[i]) && num == 0)
		return (num);
	while (str[i + decimals] && ft_isdigit(str[i + decimals]))
		num = num * 10 + (str[i + decimals++] - '0');
	while (decimals--)
		num /= 10;
	return (num * sign);
}

double	ft_atod(const char *str)
{
	int		i;
	int		sign;
	double	num;

	i = 0;
	sign = 1;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && ft_isplusminus(str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	num = ft_atod_parse(str, i, sign);
	return (num);
}
