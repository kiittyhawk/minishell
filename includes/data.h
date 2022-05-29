/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:42:30 by llornel           #+#    #+#             */
/*   Updated: 2022/03/24 22:01:58 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct s_token_list
{
	int		code;
	char	*word;
}				t_token_list;

typedef struct s_var
{
	char	*name;
	char	*value;
	char	*exportstr;
	int		attributes;
}				t_var;

typedef struct s_word
{
	int		type;
	char	*data;
	char	*original;
}				t_word;

typedef struct s_wordlist
{
	int		type;
	t_list	*words;
}				t_wordlist;

typedef struct s_redirect
{
	int		type;
	char	*data;
	char	*original;
	char	*here_doc_eof;
}				t_redirect;

typedef struct s_command
{
	int		type;
	t_list	*words;
	t_list	*redirects;
}				t_command;

typedef struct s_cmdlist
{
	int		type;
	t_list	*commands;
}				t_cmdlist;

typedef struct s_exec_cmd
{
	int		type;
	char	**cmd;
	pid_t	pid;
	t_list	*redirects;
}				t_exec_cmd;

typedef struct s_execlist
{
	int		type;
	t_list	*exec_cmds;
}				t_execlist;

t_var			*ft_var_new(char *name, char *value, int attributes);
t_var			*ft_var_copy(t_var *var);
void			*ft_var_dup(void *ptr);
void			ft_var_free(void *ptr);
void			ft_var_add(t_list **vars, char *name, char *value,
					int attributes);

t_word			*ft_word_new(int type, char *data, char *original);
t_word			*ft_word_copy(t_word *word);
void			*ft_word_dup(void *ptr);
void			ft_word_del(t_word *word, void (*del)(void*));
void			ft_word_free(void *ptr);
void			ft_word_add(t_list **words, int type, char *data,
					char *original);

t_wordlist		*ft_wordlist_new(int type, t_list *words);
t_wordlist		*ft_wordlist_copy(t_wordlist *wordlist);
void			*ft_wordlist_dup(void *ptr);
void			ft_wordlist_free(void *ptr);
void			ft_wordlist_add(t_list **wordlist, t_list *words, int type);

t_redirect		*ft_redirect_new(int type, char *data, char *original,
					char *here_doc_eof);
t_redirect		*ft_redirect_copy(t_redirect *redirect);
void			*ft_redirect_dup(void *ptr);
void			ft_redirect_free(void *ptr);

t_command		*ft_command_new(int type, t_list *words, t_list *redirects);
t_command		*ft_command_copy(t_command *command);
void			*ft_command_dup(void *ptr);
void			ft_command_free(void *ptr);
void			ft_command_add(t_list **command, int type, t_list *words,
					t_list *redirects);

t_cmdlist		*ft_cmdlist_new(int type, t_list *commands);
t_cmdlist		*ft_cmdlist_copy(t_cmdlist *cmdlist);
void			*ft_cmdlist_dup(void *ptr);
void			ft_cmdlist_free(void *ptr);
void			ft_cmdlist_add(t_list **cmdlist, t_list *commands, int type);

t_exec_cmd		*ft_exec_cmd_new(char **cmd, int type, pid_t pid,
					t_list *redirects);
t_exec_cmd		*ft_exec_cmd_copy(t_exec_cmd *exec_cmd);
void			*ft_exec_cmd_dup(void *ptr);
void			ft_exec_cmd_free(void *ptr);

t_execlist		*ft_execlist_new(int type, t_list *exec_cmds);
t_execlist		*ft_execlist_copy(t_execlist *execlist);
void			*ft_execlist_dup(void *ptr);
void			ft_execlist_free(void *ptr);
void			ft_execlist_add(t_list **execlist, t_list *exec_cmds, int type);

#endif
