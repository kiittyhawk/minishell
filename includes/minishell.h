/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:25:37 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/01 18:01:35 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
// # include <readline/readline.h>
// # include <readline/history.h>

typedef struct s_env
{
	char			*key;
	char			*sep;
	char			*value;
	struct s_env	*next;
	struct s_env	*alpha_next;
}	t_env;

/*check_syntax*/
void 	skip_spaces(char **line);
int		wrong_pipe(char *line);
int		double_semicolon(char *line);
int		wrong_semicolon(char *line);
char	*first_redirect(char *line);
char	*wrong_redirects(char *line);
int		empty_redirects(char *line);
char	*search_err(char *line);

/*parcer*/
int		check_syntax(char *line);
int		parser(char *line);

/*parse_env*/
void	add_env(char *env, t_env **envp);
void	parse_env(char **env, t_env **data);
void	print_env(t_env **data, char *flag);
void	increment(t_env *envp);
void	shlvl_increment(t_env *envp);

/*init_list*/
t_env	**init_env();
t_env	*init_elem(char *key, char *sep, char *val);
void	add_elem(t_env **head, t_env *elem);

#endif
