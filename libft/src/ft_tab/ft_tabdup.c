/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:53:44 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:13:40 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **tab)
{
	size_t	i;
	size_t	size;
	char	**tmp;

	if (tab == NULL)
		return (NULL);
	size = ft_tabsize(tab) + 1;
	tmp = (char **)malloc(sizeof(char *) * size);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		tmp[i] = ft_strdup(tab[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}
