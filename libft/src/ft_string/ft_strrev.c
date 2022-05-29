/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:25:02 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:13:03 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap_char(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_strrev(char *str)
{
	size_t	length;
	size_t	i;

	length = ft_strlen(str);
	i = 0;
	while (i < length / 2)
	{
		ft_swap_char(&str[i], &str[length - i - 1]);
		i++;
	}
}
