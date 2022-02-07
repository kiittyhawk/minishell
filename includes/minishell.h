/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:25:37 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/07 15:33:25 by jgyles           ###   ########.fr       */
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

typedef struct s_cmds
{
	char			**cmd;
	int				built;
	struct s_cmds	*next;
}	t_cmds;

typedef struct s_all
{
	t_env	**env;
	t_cmds	*cmd;
	int		cmd_count;
	int		err;
}	t_all;

/*check_syntax*/
void 	skip_spaces(char **line);
int		wrong_pipe(char *line);
int		double_semicolon(char *line);
int		wrong_semicolon(char *line);
char	*first_redirect(char *line);
char	*wrong_redirects(char *line);
int		empty_redirects(char *line);
char	*search_err(char *line);
char	*check_quot(char *line);

/*parcer*/
int		check_syntax(char *line, t_all *data);
int		parser(char *line, t_all *data);

/*parse_env*/
void	add_env(char *env, t_env **envp);
void	parse_env(char **env, t_all *data);
void	print_env(t_env **data, char *flag);
void	increment(t_env *envp);
void	shlvl_increment(t_env *envp);

/*init_list*/
t_env	**init_env();
t_env	*init_elem(char *key, char *sep, char *val);
void	add_elem(t_env **head, t_env *elem);

/*line_handler*/
char	*replace_env(char *line, int start, char *key, char *value);
char	*get_env(char *line, t_env *env, int *i);
char	*quotes_handler(char *line, int *i);
char	*remove_double_quotes(char *line, int *i);
char	*double_quotes_handler(char *line, int *i, t_all *data);

/*err_handler*/
char	*return_err(char *line, int *i, t_all *data);

#endif
