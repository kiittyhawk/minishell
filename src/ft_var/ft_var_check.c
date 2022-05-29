/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:32:04 by llornel           #+#    #+#             */
/*   Updated: 2022/03/13 17:17:02 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_name_char(int c)
{
	if (ft_isalnum(c) || c == '_')
		return (1);
	return (0);
}

int	ft_is_name_starter(int c)
{
	if (ft_isalpha(c) || c == '_')
		return (1);
	return (0);
}
