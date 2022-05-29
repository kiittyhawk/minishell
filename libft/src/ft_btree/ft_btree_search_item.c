/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search_item.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:49:37 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:10:06 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_btree_search_item(t_btree *root, void *data_ref,
								int (*cmpf)(void *, void *))
{
	void	*find;

	find = NULL;
	if (root != NULL && cmpf != NULL && data_ref != NULL)
	{
		find = ft_btree_search_item(root->left, data_ref, cmpf);
		if ((find == NULL) && ((*cmpf)(root->item, data_ref) == 0))
			return (root->item);
		if (find == NULL)
			find = ft_btree_search_item(root->right, data_ref, cmpf);
	}
	return (find);
}
