/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:25:32 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:13:48 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabjoin(char **tab1, char **tab2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	**tab;

	size = ft_tabsize(tab1) + ft_tabsize(tab2) + 1;
	tab = (char **)malloc(sizeof(char *) * size);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (tab1 && tab1[i])
	{
		tab[i] = ft_strdup(tab1[i]);
		i++;
	}
	j = 0;
	while (tab2 && tab2[j])
	{
		tab[i] = ft_strdup(tab2[j]);
		j++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
