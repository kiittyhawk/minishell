/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_level_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:59:54 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:09:55 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_btree_level_count(t_btree *root)
{
	if (root == NULL || (root->left == NULL && root->right == NULL))
		return (0);
	return (ft_max(ft_btree_level_count(root->left),
			ft_btree_level_count(root->right)) + 1);
}
