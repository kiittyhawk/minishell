/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:25:40 by llornel           #+#    #+#             */
/*   Updated: 2022/03/15 18:31:52 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_var_lstadd(t_list **vars, char *str, int attributes)
{
	t_var	*new;
	char	*name;
	char	*value;
	int		ret;

	ret = EXIT_SUCCESS;
	ft_var_parse(str, &name, &value);
	new = ft_var_new(name, value, attributes);
	if (new == NULL)
		ret = EXIT_FAILURE;
	if (ret == EXIT_SUCCESS)
		ft_lstadd_back(vars, ft_lstnew(new));
	return (ret);
}

int	ft_vars_init(t_list **vars, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_var_lstadd(vars, envp[i], VAR_EXPORT);
		i++;
	}
	return (EXIT_SUCCESS);
}
