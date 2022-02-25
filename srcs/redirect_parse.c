/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:58:27 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/25 15:10:15 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// char	*set_cmd(char *line, int i)
// {
// 	int	j;
// 	int	len;

// 	j = 0;
// 	len = 0;
// 	while (line[j] && line[j] == ' ')
// 		j++;
// 	if (j == i)
// 		return (NULL);
// 	while (line[j] && !is_redirect(line[j]))
// 	{
// 		len++;
// 		j++;
// 	}
// 	return(ft_substr(line, j, len));
// }

char	*set_filename(char *line, int *i)
{
	int	j;

	j = 0;
	while (line[*i] && line[*i] == ' ')
		(*i)++;
	j = *i;
	while (line[*i] && (line[*i] != ' ' && line[*i] != '|' && !is_redirect(line[*i])))
		(*i)++;
	return (ft_substr(line, j, *i - j));
}

t_redir	*init_redir(void)
{
	t_redir	*node;

	node = malloc(sizeof(t_redir));
	node->next = NULL;
	node->type = 0;
	node->type = 1;
	node->out = 0;
	node->last = 1;
	return (node);
}

t_redir	*add_redir(char *line, int *i, t_all *data)
{
	t_redir	*node;

	node = init_redir();
	node->cmd_count = data->cmd_count;
	if (line[*i + 1] && line[*i + 1] == '>' && line[*i] == '>')
	{
		node->type++;
		node->out = 1;
		*i += 2;
	}
	if (line[*i + 1] && line[*i + 1] != '>' && line[*i] == '>')
	{
		node->out = 1;
		(*i)++;
	}
	if (line[*i + 1] && line[*i + 1] == '<' && line[*i] == '<')
	{
		node->type++;
		*i += 2;
	}
	if (line[*i + 1] && line[*i + 1] != '<' && line[*i] == '<')
		(*i)++;
	node->filename = set_filename(line, i);
	return (node);
}

int	set_last(t_redir *redir, t_redir *redirs)
{
	if (redir->out)
	{
		while (redirs && redirs != redir)
		{
			if (redirs->out && redirs->last == 1)
				redirs->last = 0;
			redirs = redirs->next;
		}
	}
	else
	{
		while (redirs && redirs != redir)
		{
			if (!redirs->out && redirs->last == 1)
				redirs->last = 0;
			redirs = redirs->next;
		}
	}
	return (1);
}

char	*parse_redir(char *line, int *i, t_all *data)
{
	t_cmds	*cmd;
	t_redir	*redir;
	t_redir	*redirs;

	cmd = data->cmd;
	redir = cmd->redirect;
	redirs = cmd->redirect;
	if (!cmd->redirect)
	{
		cmd->redirect = add_redir(line, i, data);
	}
	else
	{
		while (cmd->redirect->next)
			cmd->redirect = cmd->redirect->next;
		cmd->redirect->next = add_redir(line, i, data);
		cmd->redirect->next->last = set_last(cmd->redirect->next, redirs);
		cmd->redirect = redir;
	}
	return (line);
}
