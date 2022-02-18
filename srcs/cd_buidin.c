/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_buidin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:56:00 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/18 17:43:34 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	cd_buildin(char **args)
{
	if (args[1])
	{
		if (count_str(args) > 1)
		{
			printf("minishell: cd: ");
			ft_putendl_fd(strerror(E2BIG), 2);
			return (2);
		}
		if (chdir(args[0]))
		{
			printf("minishell: cd: ");
			ft_putendl_fd(strerror(errno), 2);
			return (1);
		}
	}
	return (0);
}
