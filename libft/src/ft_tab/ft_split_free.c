/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:26:14 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:13:26 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_str_free(char **str)
{
	free(*str);
	*str = NULL;
}

void	ft_split_free(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		ft_str_free(&split[i]);
		i++;
	}
	free(split);
}
