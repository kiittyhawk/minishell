/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 09:24:36 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:12:32 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strisnumber(char *str)
{
	int	i;
	int	isdigit;

	i = 0;
	isdigit = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && ft_isplusminus(str[i]))
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		isdigit = 1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (false);
		i++;
	}
	if (isdigit == 0)
		return (false);
	return (true);
}
