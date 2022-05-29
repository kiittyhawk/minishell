/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strischar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 02:27:53 by llornel           #+#    #+#             */
/*   Updated: 2022/03/11 02:30:46 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strischar(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != (char)c)
			return (false);
		i++;
	}
	return (true);
}
