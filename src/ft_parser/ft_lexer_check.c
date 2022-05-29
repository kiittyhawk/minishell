/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:49:49 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 16:05:14 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_quotes(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
	{
		if (*tmp == TOKEN_DQUOTE)
			tmp = ft_strchr(tmp + 1, TOKEN_DQUOTE);
		if (tmp == NULL)
			return (1);
		if (*tmp == TOKEN_SQUOTE)
			tmp = ft_strchr(tmp + 1, TOKEN_SQUOTE);
		if (tmp == NULL)
			return (1);
		tmp++;
	}
	return (0);
}
