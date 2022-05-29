/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_prefix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:44:30 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:20:10 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root == 0)
		return ;
	(*applyf)(root->item);
	ft_btree_apply_prefix(root->left, applyf);
	ft_btree_apply_prefix(root->right, applyf);
}

void	ft_btree_apply_node_prefix(t_btree *root, void (*applyf)(t_btree *))
{
	if (root == 0)
		return ;
	(*applyf)(root);
	ft_btree_apply_node_prefix(root->left, applyf);
	ft_btree_apply_node_prefix(root->right, applyf);
}
