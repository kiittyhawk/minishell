/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_tilde.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 00:29:04 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 15:17:00 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_is_tildend(int c)
{
	if (c == '\0' || c == '/' || c == ':')
		return (1);
	return (0);
}

static int	ft_unquoted_tilde_word(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_tildend(str[i]) == 0)
	{
		if (str[i] == '\\' || str[i] == '\'' || str[i] == '"')
			return (0);
		i++;
	}
	return (1);
}

static char	*ft_path_with_tilde(char *prefix, const char *suffix, int suffind)
{
	char	*ret;
	int		plen;
	int		slen;

	plen = 0;
	if (prefix && *prefix)
		plen = ft_strlen(prefix);
	slen = ft_strlen(suffix + suffind);
	ret = (char *)malloc(sizeof(char) * (plen + slen + 1));
	if (ret == NULL)
		return ((char *) NULL);
	if (plen)
		ft_strcpy(ret, prefix);
	ft_strcpy(ret + plen, suffix + suffind);
	return (ret);
}

static char	*ft_expand_tilde_word(const char *str)
{
	int		i;
	char	*dirname;
	t_var	*var;

	i = 1;
	if (str == NULL)
		return ((char *) NULL);
	if (*str != '~')
		return (ft_strdup(str));
	if (str[1] == '\0' || str[1] == '/')
	{
		var = ft_var_find(g_params.vars, "HOME");
		if (var == NULL || var->value == NULL || *var->value == '\0')
			dirname = ft_get_work_dir();
		else
			dirname = ft_strdup(var->value);
		return (ft_path_with_tilde(dirname, str, 1));
	}
	return ((char *) NULL);
}

char	*ft_expand_tilde(char *str)
{
	int		i;
	char	*ret;

	i = 1;
	if (*str == '~')
		i = ft_unquoted_tilde_word(str);
	if (i != 0)
		ret = ft_expand_tilde_word(str);
	else
		ret = ft_strdup(str);
	return (ret);
}
