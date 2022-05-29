/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:02:00 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 05:13:54 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isoverflow(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

static int	ft_checkoverflow(unsigned long num, int sign)
{
	if (sign == -1)
		num--;
	if (num > MAX_LL_INT)
		return (1);
	return (0);
}

static int	ft_handle_start(const char *str, int *sign)
{
	int		i;

	i = 0;
	*sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (ft_isplusminus(str[i]))
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

long	ft_atol(const char *str)
{
	int						i;
	int						sign;
	unsigned long long int	num;

	i = ft_handle_start(str, &sign);
	num = 0;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i++] - '0');
		if (ft_checkoverflow(num, sign) == 1)
		{
			num = ft_isoverflow(sign);
			break ;
		}
	}
	return (num * sign);
}

int	ft_atol_num(const char *str, long *nbr)
{
	int						i;
	int						sign;
	unsigned long long int	num;

	i = ft_handle_start(str, &sign);
	num = 0;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i++] - '0');
		if (ft_checkoverflow(num, sign) == 1)
		{
			*nbr = ft_isoverflow(sign);
			return (0);
		}
	}
	*nbr = (long)(num * sign);
	return (1);
}
