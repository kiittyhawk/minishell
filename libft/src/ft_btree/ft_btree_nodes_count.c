/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_nodes_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:00:48 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:10:04 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_btree_nodes_count(t_btree *root)
{
	static int	node_count;

	if (root == NULL)
		return (0);
	node_count++;
	ft_btree_nodes_count(root->left);
	ft_btree_nodes_count(root->right);
	return (node_count);
}
