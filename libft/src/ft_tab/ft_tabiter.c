/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:47:55 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:13:46 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabiter(char **tab, void (*f)(char *))
{
	int	i;

	if (tab == NULL || f == NULL)
		return ;
	i = 0;
	while (tab[i])
	{
		(*f)(tab[i]);
		i++;
	}
}
