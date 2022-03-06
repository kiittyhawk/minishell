/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:03:39 by jgyles            #+#    #+#             */
/*   Updated: 2022/03/06 19:38:32 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


void	gnl_init_strings(char **end, char **line)
{
	*line = ft_strdup("\0");
	*end = ft_strdup("\0\0");
	if (!*line || !*end)
		return ;
}

void	gnl(char **line)
{
	char	*buf;
	char	*tmp;
	int		bytes_was_read;

	gnl_init_strings(&buf, line);
	while (*buf != '\n')
	{
		bytes_was_read = read(0, buf, 1);
		if (bytes_was_read == -1)
			return ;
		buf[bytes_was_read] = '\0';
		if (*buf == '\n')
			break ;
		if (!*buf)
		{
			*line = NULL;
			return ;
		}
		tmp = ft_strjoin(*line, buf);
		if (!tmp)
		{
			free(buf);
			return ;
		}
		free(*line);
		*line = tmp;
	}
	free(buf);
}

void	loop_heredoc(char *limiter, int fd)
{
	char	*line;

	while (1)
	{
		ft_putstr_fd("> ", 1);
		gnl(&line);
		if (!line)
		{
			ft_putstr_fd("  \b\b", 1);
			break ;
		}
		if (ft_strcmp(line, limiter))
		{
			ft_putstr_fd(line, fd);
			ft_putstr_fd("\n", fd);
		}
		else
			break ;
		free(line);
	}
}

void	heredoc(char *limiter, t_all *data)
{
	int		fd;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		data->err = errno;
		ft_exit(data->err, "fork");
	}
	if (pid != 0)
		signal(SIGINT, SIG_IGN);
	if (pid == 0)
	{
		fd = open("heredoc", O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 0644);
		if (fd == -1)
			ft_exit(errno, "heredoc");
		loop_heredoc(limiter, fd);
		close(fd);
	}
	waitpid(pid, NULL, 0);
	signal(SIGINT, &ft_handler_sigint);
}
