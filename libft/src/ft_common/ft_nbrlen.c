/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:58:50 by llornel           #+#    #+#             */
/*   Updated: 2022/02/06 15:23:10 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(long nbr)
{
	int	size;

	size = 0;
	if (nbr <= 0)
	{
		size += 1;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		size++;
		nbr /= 10;
	}
	return (size);
}

int	ft_nbrlen_base(unsigned long n, int base)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}
