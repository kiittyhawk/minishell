/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 00:39:37 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 00:39:52 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_del(t_env *env, void (*del)(void*))
{
	if (env == NULL || del == NULL)
		return ;
	if (env)
	{
		(*del)(env->key);
		(*del)(env->value);
		free(env);
	}
}
