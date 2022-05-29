/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:43:25 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:09:10 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root == 0)
		return ;
	ft_btree_apply_infix(root->left, applyf);
	(*applyf)(root->item);
	ft_btree_apply_infix(root->right, applyf);
}

void	ft_btree_apply_node_infix(t_btree *root, void (*applyf)(t_btree *))
{
	if (root == 0)
		return ;
	ft_btree_apply_node_infix(root->left, applyf);
	(*applyf)(root);
	ft_btree_apply_node_infix(root->right, applyf);
}
