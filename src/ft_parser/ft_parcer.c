/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 23:01:28 by llornel           #+#    #+#             */
/*   Updated: 2022/03/25 14:43:06 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parser(t_list **cmdlist, t_list **words)
{
	int			ret;
	t_list		*wordlist;

	wordlist = (t_list *) NULL;
	ret = EXIT_SUCCESS;
	ret = ft_parcer_command(&wordlist, *words);
	ret = ft_parcer_pipe(cmdlist, wordlist);
	ft_lstclear(&wordlist, ft_wordlist_free);
	return (ret);
}
