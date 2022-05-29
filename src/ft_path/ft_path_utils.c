/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:37:04 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 15:37:32 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_parse_path(char *path, const char *cmd)
{
	char	**dir;
	char	*curr;
	int		i;

	dir = ft_split(path, ':');
	if (dir == NULL)
		return (NULL);
	i = 0;
	curr = NULL;
	while (dir[i])
	{
		curr = ft_path_join(dir[i], (char *)cmd);
		if (access(curr, X_OK) != -1)
			break ;
		ft_strdel(&curr);
		i++;
	}
	ft_tabfree(dir);
	return (curr);
}

char	*ft_get_path(char **env, char *cmd)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_parse_path(env[i] + 5, cmd);
			if (path == NULL)
			{
				ft_report_error(cmd, ERR_MSG_COMMANDS);
				break ;
			}
		}
		i++;
	}
	return (path);
}

int	ft_absolute_pathname(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (ft_is_abspath((char *)str))
		return (1);
	if (str[0] == '.' && ft_is_pathsep(str[1]))
		return (1);
	if (str[0] == '.' && str[1] == '.' && ft_is_pathsep(str[2]))
		return (1);
	return (0);
}

int	ft_absolute_program(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (ft_strchr(str, '/') != NULL)
		return (1);
	return (0);
}

char	*ft_path_join(const char *s1, const char *s2)
{
	char	*tmp;
	char	*path;

	tmp = ft_strjoin(s1, "/");
	path = ft_strjoin(tmp, s2);
	ft_memdel(tmp);
	return (path);
}
