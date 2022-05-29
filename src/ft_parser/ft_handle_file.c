/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:55:00 by llornel           #+#    #+#             */
/*   Updated: 2022/03/25 18:12:55 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_open_redirect_file(char *filename, int type)
{
	int		fd;
	int		mode;

	fd = -1;
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if (type == TOKEN_GREAT)
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, mode);
	else if (type == TOKEN_DGREAT)
		fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, mode);
	else if (type == TOKEN_LESS)
		fd = open(filename, O_RDONLY, mode);
	return (fd);
}

int	ft_handle_open_file(char *filename, int type, int *fd)
{
	if (*fd != -1 && *fd != STDOUT)
		ft_close_fd(*fd);
	*fd = ft_open_redirect_file(filename, type);
	if (*fd == -1)
		return (ft_failure_error(filename));
	return (EXIT_SUCCESS);
}

int	ft_handle_open_heredoc(char *data, int *fd)
{
	int		pipefd[2];

	if (*fd != -1 && *fd != STDIN)
		ft_close_fd(*fd);
	if (pipe(pipefd) == -1)
		return (ft_failure_error("pipe"));
	*fd = pipefd[0];
	if (data != NULL)
		ft_putstr_fd(pipefd[1], data);
	ft_close_fd(pipefd[1]);
	return (EXIT_SUCCESS);
}
