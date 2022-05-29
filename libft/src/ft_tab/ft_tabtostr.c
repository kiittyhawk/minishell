/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:59:40 by llornel           #+#    #+#             */
/*   Updated: 2022/03/23 21:25:10 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_tabtostr(char **tab, char *sep)
// {
// 	size_t	i;
// 	char	*str;
// 	char	*tmp_tab;
// 	char	*tmp_str;

// 	if (tab == NULL)
// 		return (NULL);
// 	if (ft_tabsize(tab) == 1)
// 		return (ft_strdup(tab[0]));
// 	str = ft_strdup("");
// 	i = 0;
// 	while (tab[i])
// 	{
// 		tmp_str = str;
// 		tmp_tab = ft_strjoin(tab[i], sep);
// 		str = ft_strjoin(tmp_str, tmp_tab);
// 		ft_memdel(tmp_str);
// 		ft_memdel(tmp_tab);
// 		i++;
// 	}
// 	return (str);
// }

char	*ft_tabtostr(char **tab, char *sep)
{
	size_t	i;
	char	*str;

	if (tab == NULL)
		return (NULL);
	str = (char *) NULL;
	i = 0;
	while (tab[i])
	{
		if (i != 0)
			ft_strset((void **)&str, ft_strjoin(str, sep));
		if (str == NULL)
			str = ft_strdup(tab[i]);
		else
			ft_strset((void **)&str, ft_strjoin(str, tab[i]));
		i++;
	}
	return (str);
}
