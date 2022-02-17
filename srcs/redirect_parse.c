/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:58:27 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/16 16:01:44 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// char	*set_cmd(char *line, int i, t_all *data)
// {
// 	int		j;
// 	int		len;

// 	j = 0;
// 	len = 0;
// 	while (line[j] && line[j] == ' ')
// 		j++;
// 	if (j == i)
// 		return (NULL);
// 	return(ft_substr(line, j, i - j));
// }

// t_redir	*add_redir(char *line, int *i, t_all *data)
// {
// 	t_redir	*node;

// 	node = malloc(sizeof(t_redir));
// 	node->cmd_count = data->cmd_count;
// 	node->next = NULL;
// 	if (line[*i + 1] && line[*i + 1] == '>' && line[*i] == '>')
// 	{
// 		node->type = 2;
// 		node->out = 1;
// 		node->in = 0;
// 		node->cmd = set_cmd(line, *i, data);
// 		(*i)++;
// 	}
// 	if (line[*i + 1] && line[*i + 1] != '>' && line[*i] == '>')
// 	{
// 		node->type = 1;
// 		node->out = 1;
// 		node->in = 0;
// 		node->cmd = set_cmd(line, *i, data);
// 	}
// 	if (line[*i + 1] && line[*i + 1] == '<' && line[*i] == '<')
// 	{
// 		node->type = 2;
// 		node->out = 0;
// 		node->in = 1;
// 		node->cmd = set_cmd(line, *i, data);
// 		(*i)++;
// 	}
// 	if (line[*i + 1] && line[*i + 1] != '<' && line[*i] == '<')
// 	{
// 		node->type = 1;
// 		node->out = 0;
// 		node->in = 1;
// 		node->cmd = set_cmd(line, *i, data);
// 	}
// 	return (node);
// }

// char	*parse_redir(char *line, int *i, t_all *data)
// {
// 	t_cmds	*cmd;
// 	t_redir	*redir;

// 	cmd = data->cmd;
// 	redir = cmd->redirect;
// 	if (!cmd->redirect)
// 	{
// 		cmd->redirect = add_redir(line, i, data);
// 	}
// 	else
// 	{
// 		while (cmd->redirect->next)
// 			cmd->redirect = cmd->redirect->next;
// 		cmd->redirect->next = add_redir(line, i, data);
// 		cmd->redirect = redir;
// 	}
// 	return (line);
// }