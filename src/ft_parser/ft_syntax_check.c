/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:21:49 by llornel           #+#    #+#             */
/*   Updated: 2022/03/25 12:48:11 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_next(char **tab, int *i)
{
	*i += 1;
	while (tab[*i])
	{
		if (!ft_strisempty(tab[*i]))
			return (tab[*i]);
		*i += 1;
	}
	return ((char *) NULL);
}

static int	ft_check_valid_next(char *str, char *next)
{
	if (next == NULL)
	{
		if (*str == ';')
			return (EXIT_SUCCESS);
		return (ft_syntax_error(ERR_MSG_SYNTAX_ERROR, "newline"));
	}
	else if ((ft_str_is_command_sep(str) == 1 || ft_str_is_pipe(str) == 1)
		&& (ft_str_is_command_sep(next) == 1 || ft_str_is_pipe(next) == 1))
		return (ft_syntax_error(ERR_MSG_SYNTAX_ERROR, next));
	else if ((ft_str_is_redirect(str) == 1 || ft_str_is_heredoc(str) == 1)
		&& ft_str_is_special_token(next) == 1)
		return (ft_syntax_error(ERR_MSG_SYNTAX_ERROR, next));
	return (EXIT_SUCCESS);
}

static int	ft_check_valid_token(char **tab, int *i)
{
	char	*next;
	char	*curr;
	int		ret;

	while (ft_strisempty(tab[*i]))
		*i += 1;
	if (*i == 0 && (ft_str_is_command_sep(tab[*i]) == 1
			|| ft_str_is_pipe(tab[*i]) == 1))
		return (ft_syntax_error(ERR_MSG_SYNTAX_ERROR, tab[*i]));
	else if (ft_str_is_special_token(tab[*i]) == 1)
	{
		curr = tab[*i];
		next = ft_get_next(tab, i);
		if (next == NULL)
			*i = -1;
		ret = ft_check_valid_next(curr, next);
		if (ret != EXIT_SUCCESS)
			return (ret);
	}
	return (EXIT_SUCCESS);
}

int	ft_syntax_check(t_list *words)
{
	char	**tab;
	int		i;
	int		ret;

	tab = ft_list_to_tab(words, ft_copy_data_from_word);
	if (tab == NULL)
		return (EXIT_SUCCESS);
	i = 0;
	ret = EXIT_SUCCESS;
	while (tab[i])
	{
		if (ft_str_is_special_token(tab[i]) == 1)
		{
			ret = ft_check_valid_token(tab, &i);
			if (ret != EXIT_SUCCESS || i == -1)
				break ;
		}
		else
			i++;
	}
	ft_tabfree(tab);
	return (ret);
}
