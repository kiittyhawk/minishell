/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:46:02 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 16:46:04 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execute_cmd(t_exec_cmd *exec_cmd)
{
	int	ret;

	ret = ft_do_redirects(exec_cmd);
	if (ret == EXIT_SUCCESS)
		ret = ft_do_simplecmd(exec_cmd);
	return (ret);
}
