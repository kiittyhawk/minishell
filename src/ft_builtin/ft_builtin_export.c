/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:43:04 by llornel           #+#    #+#             */
/*   Updated: 2022/03/24 09:47:15 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_var_export(t_list *vars, char *str)
{
	char	*name;
	char	*value;
	int		ret;

	ret = EXIT_SUCCESS;
	ft_var_parse(str, &name, &value);
	if (ft_valid_name(name) == 0)
	{
		ft_builtin_error("export", str, ERR_MSG_IDENTIFIER);
		ret = EXIT_FAILURE;
	}
	else
	{
		ft_var_set_export(vars, name, value);
	}
	ft_memdel(name);
	ft_memdel(value);
	return (ret);
}

static void	ft_vars_sort_print(t_list *vars)
{
	char	**envp;
	int		i;
	t_list	*tmp;

	tmp = vars;
	envp = ft_list_to_tab(tmp, ft_copy_declare_from_var);
	if (envp == NULL)
		return ;
	ft_tabsort(envp);
	i = 0;
	while (envp[i])
	{
		printf("declare -x %s\n", envp[i]);
		i++;
	}
	ft_tabfree(envp);
}

int	ft_builtin_export(char **args, t_list *vars)
{
	int		i;
	int		ret;

	if (args == NULL)
		return (EXIT_FAILURE);
	if (args[0] && !ft_strnstr(args[0], "export", ft_strlen("export")))
		return (EXIT_FAILURE);
	if (args[1] == NULL)
		ft_vars_sort_print(vars);
	ret = EXIT_SUCCESS;
	i = 1;
	while (args[i])
	{
		if (ft_var_export(vars, args[i]) != EXIT_SUCCESS)
			ret = EXIT_FAILURE;
		i++;
	}
	return (ret);
}
