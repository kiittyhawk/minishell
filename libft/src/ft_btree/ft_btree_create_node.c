/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:45:37 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:09:48 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_create_node(void *item)
{
	t_btree		*btree;

	btree = (t_btree *)malloc(sizeof(t_btree));
	if (btree == NULL)
		return (NULL);
	btree->item = item;
	btree->left = NULL;
	btree->right = NULL;
	return (btree);
}
