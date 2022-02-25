/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:19:32 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/24 18:37:06 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		ft_putchar(str[i]);
	ft_putchar('\0');
}

static int	get_count(char **args)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (args[++i])
		count++;
	return (count);
}

void	echo_buildin(char **args)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	if (args && args[0][0] == '-' && args[0][1] == 'n' && args[0][2] == '\0')
	{
		flag = 1;
		i++;
	}
	while (args && i < get_count(args))
	{
		ft_putstr(args[i++]);
		if (i < get_count(args))
			ft_putchar(' ');
	}
	if (!flag)
		ft_putchar('\n');
}
