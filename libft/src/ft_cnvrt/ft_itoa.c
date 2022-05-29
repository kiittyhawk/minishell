/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:01:40 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:10:23 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(long nbr)
{
	int	size;

	size = 0;
	while (nbr >= 10)
	{
		nbr /= 10;
		size++;
	}
	return (size + 1);
}

static char	*ft_itoa_str(char *str, long nbr, int size, int sign)
{
	int				i;

	i = 0;
	while (nbr >= 10)
	{
		str[i] = '0' + (nbr % 10);
		nbr /= 10;
		i++;
	}
	str[i] = '0' + nbr;
	if (sign)
		str[++i] = '-';
	str[size] = '\0';
	ft_strrev(str);
	return (str);
}

char	*ft_itoa(int n)
{
	int				sign;
	int				size;
	long			nbr;
	char			*str;

	nbr = n;
	sign = (nbr < 0);
	if (sign)
		nbr = -nbr;
	size = ft_size(nbr) + sign;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	ft_itoa_str(str, nbr, size, sign);
	return (str);
}

char	*ft_itoa_base(unsigned long n, int base)
{
	char	*ret;
	char	*numbers;
	int		size;

	size = ft_nbrlen_base(n, base);
	ret = (char *)malloc(sizeof(char) * size + 1);
	if (ret == NULL)
		return (NULL);
	ret[size--] = '\0';
	numbers = ft_strdup("0123456789abcdef");
	while (size >= 0)
	{
		ret[size--] = numbers[n % base];
		n /= base;
	}
	free(numbers);
	return (ret);
}
