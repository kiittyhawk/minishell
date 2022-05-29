/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:08:07 by llornel           #+#    #+#             */
/*   Updated: 2022/03/24 17:05:30 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_wildcard(char *str, int *start)
{
	int		end;
	int		ret;
	char	*tmp;

	if (str == NULL)
		return (0);
	if (str[*start] != WILDCARD_CHAR)
		return (0);
	if ((*start > 0) && !ft_isspace(str[*start - 1]))
		return (0);
	end = *start;
	while (str[end] && !ft_isspace(str[end]))
		end++;
	tmp = ft_substr(str, *start, end - *start);
	*start = end;
	ret = ft_striswildcard(tmp);
	ft_memdel(tmp);
	return (ret);
}

char	*ft_get_strwildcard(char *str, int *start)
{
	int		end;
	char	*tmp;

	if (str == NULL)
		return (NULL);
	if (str[*start] != WILDCARD_CHAR)
		return (ft_strdup(str));
	if ((*start > 0) && !ft_isspace(str[*start - 1]))
		return (ft_strdup(str));
	end = *start;
	while (str[end] && !ft_isspace(str[end]))
		end++;
	tmp = ft_substr(str, *start, end - *start);
	*start = end;
	return (tmp);
}

char	*ft_get_identifier(char *name)
{
	int		size;
	int		i;
	char	*tmp;
	char	*str;

	if (name == NULL || *name == '\0')
		return (NULL);
	tmp = name;
	if (*tmp == '$')
		tmp++;
	size = ft_size_name(tmp);
	if (size == 0)
		return (NULL);
	str = ft_calloc(size + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*tmp && i < size)
		str[i++] = *tmp++;
	return (str);
}

char	*ft_get_expand_env(char *str, int *start)
{
	char	*tmp;
	char	*name;

	name = ft_get_identifier(str + *start);
	tmp = ft_var_get(g_params.vars, name);
	if (tmp == NULL)
		tmp = ft_strdup("");
	*start += ft_strlen(name) - 1;
	ft_memdel(name);
	return (tmp);
}

char	*ft_get_expand_wildcard(char *str, int *start)
{
	char	*tmp;

	if (str == NULL)
		return (NULL);
	if (str[*start] != WILDCARD_CHAR)
		return (str);
	tmp = ft_get_strwildcard(str, start);
	if (ft_striswildcard(tmp))
	{
		ft_memdel(tmp);
		tmp = ft_get_dir_items(".");
	}
	return (tmp);
}
