/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:14:25 by llornel           #+#    #+#             */
/*   Updated: 2022/03/24 17:22:31 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_redirect_error(char *name, char *err)
{
	ft_putstr_fd(STDERR, ERR_PROMPT);
	ft_putstr_fd(STDERR, ": ");
	ft_putstr_fd(STDERR, name);
	ft_putstr_fd(STDERR, ": ");
	ft_putstr_fd(STDERR, err);
	ft_putstr_fd(STDERR, "\n");
	return (EXIT_FAILURE);
}

static int	ft_handle_redirects(t_list *redirects, int *in, int *out)
{
	t_redirect	*redirect;
	int			ret;

	ret = EXIT_SUCCESS;
	while (redirects)
	{
		redirect = (t_redirect *)redirects->content;
		if (redirect->data == NULL && !ft_is_heredoc(redirect->type))
			ret = ft_redirect_error(redirect->original, "ambiguous redirect");
		else if (redirect->type == TOKEN_GREAT
			|| redirect->type == TOKEN_DGREAT)
			ret = ft_handle_open_file(redirect->data, redirect->type, out);
		else if (redirect->type == TOKEN_LESS)
			ret = ft_handle_open_file(redirect->data, redirect->type, in);
		else if (ft_is_heredoc(redirect->type))
			ret = ft_handle_open_heredoc(redirect->data, in);
		if (ret != EXIT_SUCCESS)
			break ;
		redirects = redirects->next;
	}
	return (ret);
}

int	ft_do_redirects(t_exec_cmd *exec_cmd)
{
	int		status;
	int		ret;
	int		in;
	int		out;

	if (ft_exists_redirects(exec_cmd->redirects) == 0)
		return (EXIT_SUCCESS);
	in = -1;
	out = -1;
	ret = ft_handle_redirects(exec_cmd->redirects, &in, &out);
	if (ret == EXIT_SUCCESS)
		return (ft_restore_std(in, out));
	else
	{
		status = ft_close_pipe(in, out);
		return (ret);
	}
}
