/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:25:27 by llornel           #+#    #+#             */
/*   Updated: 2022/02/12 20:56:40 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_listfreeone(t_listfd *lst)
{
	if (lst)
	{
		ft_strdel(&(lst->data));
		free(lst);
	}
}

void	ft_listdelone(t_listfd **lst, t_listfd *del)
{
	t_listfd	*curr;

	if (*lst == del)
	{
		curr = *lst;
		*lst = (*lst)->next;
		ft_listfreeone(curr);
		return ;
	}
	else
	{
		curr = *lst;
		while (curr->next != NULL)
		{
			if (curr->next == del)
			{
				curr->next = del->next;
				ft_listfreeone(del);
				return ;
			}
			curr = curr->next;
		}
	}
}

t_listfd	*ft_listnew(int fd)
{
	t_listfd	*lst;

	lst = malloc(sizeof(t_listfd));
	if (lst == NULL)
		return (NULL);
	lst->data = ft_strdup("\0");
	if (lst->data == NULL)
		return (NULL);
	lst->fd = fd;
	lst->next = NULL;
	return (lst);
}

t_listfd	*ft_listadd(t_listfd **lst, int fd)
{
	t_listfd	*new;

	if (*lst == NULL)
	{
		*lst = ft_listnew(fd);
		return (*lst);
	}
	new = *lst;
	if (new->fd == fd)
		return (new);
	while (new->next != NULL)
	{
		if (new->next->fd == fd)
			return (new->next);
		new = new->next;
	}
	new->next = ft_listnew(fd);
	return (new->next);
}
