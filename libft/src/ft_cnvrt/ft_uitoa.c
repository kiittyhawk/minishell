/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 09:30:57 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:10:25 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int nbr)
{
	char	*str;
	int		size;

	size = ft_nbrlen(nbr);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size--] = '\0';
	if (nbr == 0)
		str[size] = 0 + '0';
	while (nbr > 0)
	{
		str[size--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
