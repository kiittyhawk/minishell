/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:27:59 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 18:58:45 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_sorted_items(char *items)
{
	char	**tab;

	tab = ft_split(items, ' ');
	if (tab == NULL)
		return (NULL);
	ft_tabsort(tab);
	items = ft_tabtostr(tab, " ");
	ft_split_free(tab);
	return (items);
}

char	*ft_check_dir(char *name, char *cmd)
{
	DIR				*dir;
	struct dirent	*item;
	char			*path;

	path = NULL;
	dir = opendir(name);
	if (dir == NULL)
		return (NULL);
	item = readdir(dir);
	while (item)
	{
		if (ft_strcmp(item->d_name, cmd) == 0)
			path = ft_path_join(name, item->d_name);
		item = readdir(dir);
	}
	closedir(dir);
	return (path);
}

char	*ft_get_work_dir(void)
{
	char	*work_dir;
	char	dir[PATH_MAX];

	work_dir = ft_var_get(g_params.vars, "PWD");
	if (work_dir == NULL)
	{
		work_dir = getcwd(dir, sizeof(dir));
		if (work_dir == NULL)
		{
			printf("%s: %s: %s: %s\n", ERR_PROMPT,
				ERR_MSG_WORK_DIR, ERR_MSG_BASH_GETCWD, strerror (errno));
			return (NULL);
		}
	}
	return (work_dir);
}

char	*ft_get_dir_items(char *name)
{
	DIR				*dir;
	struct dirent	*item;
	char			*items;

	items = ft_strdup("");
	dir = opendir(name);
	if (dir == NULL)
		return (items);
	item = readdir(dir);
	while (item != NULL)
	{
		if (ft_strncmp(item->d_name, ".", 1) != 0)
		{
			if (ft_strlen(items) != 0)
				ft_strset((void **)&items, ft_strjoin(items, " "));
			ft_strset((void **)&items, ft_strjoin(items, item->d_name));
		}
		item = readdir(dir);
	}
	closedir(dir);
	ft_strset((void **)&items, ft_sorted_items(items));
	return (items);
}
