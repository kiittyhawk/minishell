/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 20:48:18 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:10:20 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isoverflow(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int						i;
	int						sign;
	unsigned long long int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_isplusminus(str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (num >= MAX_LL_INT)
		{
			num = ft_isoverflow(sign);
			break ;
		}
		num = num * 10 + (str[i++] - '0');
	}
	return (num * sign);
}

int	ft_atoi_num(const char *str, int *nbr)
{
	int			i;
	int			sign;
	long int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_isplusminus(str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i++] - '0');
		if ((num * sign) > MAX_INT)
			return (0);
		if ((num * sign) < MIN_INT)
			return (0);
	}
	*nbr = (int)(num * sign);
	return (1);
}
