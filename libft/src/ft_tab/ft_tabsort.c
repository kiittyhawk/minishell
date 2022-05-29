/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 06:24:56 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:13:57 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabsort(char **tab)
{
	int		ordered;
	size_t	i;
	size_t	size;

	ordered = 0;
	size = ft_tabsize(tab);
	while (tab && ordered == 0)
	{
		ordered = 1;
		i = 0;
		while (i < size - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				ft_swap((void **)&tab[i], (void **)&tab[i + 1]);
				ordered = 0;
			}
			i++;
		}
		size--;
	}
}
