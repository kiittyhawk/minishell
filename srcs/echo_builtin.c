/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:19:32 by jgyles            #+#    #+#             */
/*   Updated: 2022/03/04 18:01:31 by jgyles           ###   ########.fr       */
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

int	echo_buildin(char **args)
{
	int	flag;
	int	i;

	flag = 0;
	i = 1;
	if (args[1] && args[1][0] == '-' && args[1][1] == 'n' && args[1][2] == '\0')
	{
		flag = 1;
		i++;
	}
	while (args && args[i] && i < get_count(args))
	{
		ft_putstr(args[i++]);
		if (i < get_count(args))
			ft_putchar(' ');
	}
	if (!flag)
		ft_putchar('\n');
	return (0);
}
