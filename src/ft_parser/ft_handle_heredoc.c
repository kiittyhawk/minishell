/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 02:47:36 by llornel           #+#    #+#             */
/*   Updated: 2022/03/24 20:43:20 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_handle_heredoc_loop(const char *delimiter, char **str)
{
	char	*input;
	int		ret;

	ret = EXIT_SUCCESS;
	input = (char *) NULL;
	while (true)
	{
		ft_memdel((void *)input);
		input = readline("> ");
		if (g_params.heredoc_status != 0 || input == NULL)
		{
			if (g_params.heredoc_status == EXIT_CTRL_C)
			{
				ret = EXIT_FAILURE;
				ft_strset((void **)str, ft_strdup(""));
			}
			break ;
		}
		if (ft_strcmp(input, delimiter) == 0)
			break ;
		ft_strset((void **)str, ft_strjoin(*str, input));
		ft_strset((void **)str, ft_strjoin(*str, "\n"));
	}
	ft_memdel((void *)input);
	return (ret);
}

int	ft_handle_heredoc(char *delimiter, char **str)
{
	int		ret;

	g_params.heredoc_status = 0;
	*str = ft_strdup("");
	ret = EXIT_SUCCESS;
	ft_set_signal_heredoc();
	ret = ft_handle_heredoc_loop(delimiter, str);
	ft_set_signal_newprompt();
	return (ret);
}
