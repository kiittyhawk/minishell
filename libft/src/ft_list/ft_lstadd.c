/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 01:32:23 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 05:14:39 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **lst, void *content, void *(*f)(void *))
{
	t_list	*new;
	void	*content_copy;

	content_copy = (*f)(content);
	new = ft_lstnew(content_copy);
	ft_lstadd_back(lst, new);
}
