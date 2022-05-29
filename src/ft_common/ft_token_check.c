/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:49:49 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 15:13:07 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_quote(int c)
{
	if (c == TOKEN_DQUOTE || c == TOKEN_SQUOTE)
		return (1);
	return (0);
}

int	ft_is_redirect(int c)
{
	if (c == TOKEN_DGREAT || c == TOKEN_GREAT || c == TOKEN_LESS)
		return (1);
	return (0);
}

int	ft_is_heredoc(int c)
{
	if (c == TOKEN_DLESS)
		return (1);
	return (0);
}

int	ft_str_is_double_token(char *str)
{
	if ((*str == TOKEN_AND && *(str + 1) == TOKEN_AND)
		|| (*str == TOKEN_PIPE && *(str + 1) == TOKEN_PIPE)
		|| (*str == TOKEN_LESS && *(str + 1) == TOKEN_LESS)
		|| (*str == TOKEN_GREAT && *(str + 1) == TOKEN_GREAT))
		return (1);
	return (0);
}
