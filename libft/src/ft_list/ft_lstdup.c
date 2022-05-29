/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:30:17 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 05:20:02 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *lst, void *(*f)(void *))
{
	t_list	*newlst;
	t_list	*tmp;
	void	*new;

	if (lst == NULL)
		return (NULL);
	newlst = (t_list *) NULL;
	tmp = lst;
	while (tmp)
	{
		new = (*f)(tmp->content);
		ft_lstadd_back(&newlst, ft_lstnew(new));
		tmp = tmp->next;
	}
	return (newlst);
}
