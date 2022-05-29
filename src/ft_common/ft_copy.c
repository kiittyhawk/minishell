/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:10:52 by llornel           #+#    #+#             */
/*   Updated: 2022/03/15 18:47:52 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_copy_char(void *ptr)
{
	char	*str;
	char	*data;

	str = (char *)ptr;
	if (str == NULL)
		return (NULL);
	data = ft_strdup(str);
	if (data == NULL)
		return (NULL);
	return ((void *)data);
}

void	*ft_copy_data_from_word(void *ptr)
{
	t_word	*word;
	char	*data;

	word = (t_word *)ptr;
	if (word == NULL)
		return (NULL);
	data = ft_strdup(word->data);
	if (data == NULL)
		return (NULL);
	return (data);
}

void	*ft_copy_exportstr_from_var(void *ptr)
{
	t_var	*var;
	char	*data;

	var = (t_var *)ptr;
	if (var == NULL)
		return (NULL);
	data = ft_strdup(var->exportstr);
	if (data == NULL)
		return (NULL);
	return (data);
}

void	*ft_copy_declare_from_var(void *ptr)
{
	t_var	*var;
	char	*data;

	var = (t_var *)ptr;
	if (var == NULL)
		return (NULL);
	data = ft_strdup(var->name);
	if (var->value)
	{
		ft_strset((void **)&data, ft_strjoin(data, "=\""));
		ft_strset((void **)&data, ft_strjoin(data, var->value));
		ft_strset((void **)&data, ft_strjoin(data, "\""));
	}	
	if (data == NULL)
		return (NULL);
	return (data);
}
