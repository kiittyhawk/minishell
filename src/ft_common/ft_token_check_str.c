/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_check_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:49:49 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 15:08:16 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_str_is_special_token(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_strcmp(str, WORD_AND_AND) == 0
		|| ft_strcmp(str, WORD_OR_OR) == 0
		|| ft_strcmp(str, WORD_SEMI) == 0
		|| ft_strcmp(str, WORD_DGREAT) == 0
		|| ft_strcmp(str, WORD_DLESS) == 0
		|| ft_strcmp(str, WORD_GREAT) == 0
		|| ft_strcmp(str, WORD_LESS) == 0
		|| ft_strcmp(str, WORD_PIPE) == 0)
		return (1);
	return (0);
}

int	ft_str_is_command_sep(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_strcmp(str, WORD_AND_AND) == 0
		|| ft_strcmp(str, WORD_OR_OR) == 0
		|| ft_strcmp(str, WORD_SEMI) == 0)
		return (1);
	return (0);
}

int	ft_str_is_redirect(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_strcmp(str, WORD_DGREAT) == 0
		|| ft_strcmp(str, WORD_GREAT) == 0
		|| ft_strcmp(str, WORD_LESS) == 0)
		return (1);
	return (0);
}

int	ft_str_is_heredoc(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_strcmp(str, WORD_DLESS) == 0)
		return (1);
	return (0);
}

int	ft_str_is_pipe(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_strcmp(str, WORD_PIPE) == 0)
		return (1);
	return (0);
}
