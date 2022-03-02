/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:58:27 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/28 18:00:18 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*set_filename(char *line, int i)
{
	int	j;

	j = 0;
	while (line[i] && is_redirect(line[i]))
		i++;
	while (line[i] && line[i] == ' ')
		(i)++;
	j = i;
	while (line[i] && (line[i] != ' ' && line[i] != '|' && !is_redirect(line[i])))
		(i)++;
	return (ft_substr(line, j, i - j));
}

t_redir	*init_redir(void)
{
	t_redir	*node;

	node = malloc(sizeof(t_redir));
	node->next = NULL;
	node->type = 1;
	node->out = 0;
	node->last = 1;
	node->limiter = NULL;
	node->filename = NULL;
	return (node);
}

t_redir	*set_heredoc(t_redir *node, char *line, int i)
{
	node->type = 2;
	node->limiter = set_filename(line, i);
	return (node);
}

t_redir	*add_redir(char *line, int *i, t_all *data)
{
	t_redir	*node;
	int		is_heredoc;

	node = init_redir();
	node->cmd_count = data->cmd_count;
	is_heredoc = 0;
	if (line[*i + 1] && line[*i + 1] == '>' && line[*i] == '>')
	{
		node->type++;
		node->out = 1;
	}
	if (line[*i + 1] && line[*i + 1] != '>' && line[*i] == '>')
		node->out = 1;
	if (line[*i + 1] && line[*i + 1] == '<' && line[*i] == '<')
	{
		is_heredoc = 1;
		node = set_heredoc(node, line, *i);
	}
	if (!is_heredoc)
		node->filename = set_filename(line, *i);
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
			if (!redirs->out && redir->type == 1 && redirs->last == 1)
				redirs->last = 0;
			redirs = redirs->next;
		}
	}
	return (1);
}

int	get_len(char *line, int i)
{
	while (line && is_redirect(line[i]))
		i++;
	while (line && line[i] == ' ')
		i++;
	while (line && line[i] != ' ')
		i++;
	return (i);
}

char	*remove_redirect(char *line, t_cmds *cmd, int i)
{
	t_redir	*tmp;
	char	*str;

	tmp = cmd->redirect;
	while (tmp->next)
		tmp = tmp->next;
	if (!tmp->limiter)
		str = malloc(ft_strlen(line) - tmp->type - ft_strlen(tmp->filename) + 1);
	else
		str = malloc(ft_strlen(line) - tmp->type - ft_strlen(tmp->limiter) + 1);
	str = ft_substr(line, 0, i);
	i = get_len(line, i);
	str = ft_strjoin(str, ft_substr(line, i, ft_strlen(line) - i));
	return (str);
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
	line = remove_redirect(line, cmd, *i);
	(*i)--;
	return (line);
}
