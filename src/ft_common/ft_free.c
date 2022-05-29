/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:46:04 by llornel           #+#    #+#             */
/*   Updated: 2022/03/25 12:48:34 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(void)
{
	ft_lstclear(&g_params.vars, ft_var_free);
	ft_memdel(g_params.vars);
	ft_memdel(g_params.pwd);
	ft_memdel(g_params.oldpwd);
}
