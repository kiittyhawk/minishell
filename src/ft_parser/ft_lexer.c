/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:51:21 by llornel           #+#    #+#             */
/*   Updated: 2022/03/25 14:33:50 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lexer(t_list	**words, char *input)
{
	int	ret;

	*words = ft_lexer_quotes(input);
	*words = ft_lexer_special(*words);
	ret = ft_syntax_check(*words);
	if (ret != EXIT_SUCCESS)
		return (ret);
	return (EXIT_SUCCESS);
}
