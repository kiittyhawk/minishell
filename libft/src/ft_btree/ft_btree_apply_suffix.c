/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_suffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:44:56 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:09:29 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root == 0)
		return ;
	ft_btree_apply_suffix(root->left, applyf);
	ft_btree_apply_suffix(root->right, applyf);
	(*applyf)(root->item);
}

void	ft_btree_apply_node_suffix(t_btree *root, void (*applyf)(t_btree *))
{
	if (root == 0)
		return ;
	ft_btree_apply_node_suffix(root->left, applyf);
	ft_btree_apply_node_suffix(root->right, applyf);
	(*applyf)(root);
}
