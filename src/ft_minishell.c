/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:28:29 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 18:33:55 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_lexpar(t_list **cmdlist, char *input)
{
	int			ret;
	t_list		*words;

	words = (t_list *) NULL;
	ret = ft_lexer(&words, input);
	if (ret != EXIT_SUCCESS)
	{
		ft_lstclear(&words, ft_word_free);
		return (ret);
	}
	ret = ft_parser(cmdlist, &words);
	ft_lstclear(&words, ft_word_free);
	if (ret != EXIT_SUCCESS)
	{
		ft_lstclear(cmdlist, ft_cmdlist_free);
		return (ret);
	}
	return (EXIT_SUCCESS);
}

static int	ft_handle_input_line(char *input)
{
	int			ret;
	t_list		*cmdlist;

	cmdlist = (t_list *) NULL;
	ret = ft_syntax(input);
	if (ret != EXIT_SUCCESS)
		return (ret);
	ret = ft_lexpar(&cmdlist, input);
	if (ret != EXIT_SUCCESS)
		return (ret);
	ret = ft_executor(&cmdlist);
	ft_lstclear(&cmdlist, ft_cmdlist_free);
	if (ret != EXIT_SUCCESS)
		return (ret);
	return (EXIT_SUCCESS);
}

int	ft_minishell_cmd(char *str)
{
	char	*input;
	int		ret;

	if (str == NULL)
		return (EXIT_SUCCESS);
	if (ft_strisempty(str))
		return (EXIT_SUCCESS);
	input = ft_strdup(str);
	if (input == NULL)
		return (ft_exit_error((void *)input, EXIT_CTRL_D));
	ret = ft_handle_input_line(input);
	ft_set_exit_status(ret);
	ft_memdel(input);
	if (g_params.exit_immediately == 1)
		return (ft_exit_error((void *)input, EXIT_FAILURE));
	return (ret);
}

int	ft_minishell(char *name)
{
	char	*input;
	int		ret;

	input = (char *) NULL;
	while (true)
	{
		ft_memdel((void *)input);
		input = readline(name);
		if (input == NULL)
			return (ft_exit_ctrld((void *)input, EXIT_CTRL_D));
		if (ft_strlen(input) == 0)
			continue ;
		add_history(input);
		if (ft_strisempty(input))
			continue ;
		ft_strset((void **)&input, ft_strtrim(input, EMPTY_CHARS));
		ret = ft_handle_input_line(input);
		ft_set_exit_status(ret);
		if (g_params.exit_immediately == 1)
			return (ft_exit_error((void *)input, EXIT_FAILURE));
	}
	return (EXIT_SUCCESS);
}
