/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:21:49 by llornel           #+#    #+#             */
/*   Updated: 2022/03/25 13:36:51 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_syntax_error(char *err, char *str)
{
	ft_putstr_fd(STDERR, ERR_PROMPT);
	ft_putstr_fd(STDERR, ": ");
	ft_putstr_fd(STDERR, err);
	ft_putstr_fd(STDERR, ": `");
	ft_putstr_fd(STDERR, str);
	ft_putstr_fd(STDERR, "'");
	ft_putstr_fd(STDERR, "\n");
	return (EXIT_SYNTAX_ERROR);
}

int	ft_syntax(char *str)
{
	int	ret;

	ret = ft_check_quotes(str);
	if (ret == 1)
		return (ft_syntax_error("syntax error", ERR_MSG_QUOTES));
	return (EXIT_SUCCESS);
}
