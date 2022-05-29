/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:33:40 by llornel           #+#    #+#             */
/*   Updated: 2022/03/24 09:47:25 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_builtin_env_print(void *ptr)
{
	t_var	*var;

	var = (t_var *)ptr;
	if (var == NULL)
		return ;
	if (var->value)
		printf("%s=%s\n", var->name, var->value);
}

int	ft_builtin_env(t_list *vars)
{
	t_list	*tmp;

	tmp = vars;
	ft_lstiter(tmp, ft_builtin_env_print);
	return (EXIT_SUCCESS);
}
