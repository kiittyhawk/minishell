/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:19:41 by llornel           #+#    #+#             */
/*   Updated: 2022/03/25 13:20:28 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define REDIR_OUTPUT		1
# define REDIR_INPUT		2
# define REDIR_APPEND_OUT	3
# define REDIR_HEREDOC		4

# define BREAK_CHARS  		"*<>&|; \t\n"
# define QUOTE_CHARS		"\"\'"
# define META_CHARS			"<>&|"
# define SPECIAL_CHARS		"\"\'<>&| \t\n"
# define IGNORE_CHARS		"\\`[]{}()"
# define EMPTY_CHARS		" \t\n"

# define DOLLAR_CHAR		'$'
# define WILDCARD_CHAR		'*'
# define BANG_CHAR			'?'

# define CH_WORD			0x1
# define CH_DOLLAR			0x2
# define CH_WILDCARD		0x4

int			ft_check_quotes(char *str);
char		*ft_get_line_quotes(char *str, int *start, char *token_name);
char		*ft_get_line_others(char *str, int *start, char *token_name);
char		*ft_get_line_word(char *str, int *start);

t_list		*ft_lexer_quotes(char *str);
t_list		*ft_lexer_special(t_list *words);
int			ft_handle_open_file(char *filename, int type, int *fd);
int			ft_handle_open_heredoc(char *data, int *fd);

int			ft_parcer_command(t_list **wordlist, t_list *words);
int			ft_parcer_pipe(t_list **cmdlist, t_list *wordslist);
int			ft_parcer_redirect(t_list **lst, t_list **redirects, int type);
int			ft_parcer_heredoc(t_list **lst, t_list **redirects, int type);
int			ft_handle_heredoc(char *delimiter, char **str);
int			ft_parcer_words(t_list **commands, t_list *lst, int type);

int			ft_syntax_error(char *err, char *str);
int			ft_syntax(char *str);
int			ft_syntax_check(t_list *words);

int			ft_lexer(t_list	**words, char *input);
int			ft_parser(t_list **cmdlist, t_list **words);

#endif