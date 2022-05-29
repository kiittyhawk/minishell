/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:58:50 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:09:51 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_insert_data(t_btree **root, void *item,
							int (*cmpf)(void *, void *))
{
	if (cmpf == NULL)
		return ;
	if (*root == NULL)
		*root = ft_btree_create_node(item);
	else if ((*cmpf)(item, (*root)->item) < 0)
		ft_btree_insert_data(&(*root)->left, item, cmpf);
	else
		ft_btree_insert_data(&(*root)->right, item, cmpf);
}
