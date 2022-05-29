/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:38:13 by llornel           #+#    #+#             */
/*   Updated: 2022/03/25 18:06:22 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

void		ft_init_shell_level(int change);

/*
** =============================================================================
** Expand Functions
** =============================================================================
*/
int			ft_check_wildcard(char *str, int *start);
char		*ft_get_expand_env(char *str, int *start);
char		*ft_get_identifier(char *name);
char		*ft_get_expand_dollar(char *str, int *start);
char		*ft_get_expand_wildcard(char *str, int *start);

void		ft_expand_word_iter(void *ptr);
void		ft_expand_redirect_iter(void *ptr);
void		ft_expand_wildcard_iter(void *ptr);

char		*ft_expand_special(char *str, char *sep, int flag);
char		*ft_expand_line(char *str, char *sep, int flags);
char		*ft_expand_tilde(char *str);
char		*ft_expand_dollar(char *str);
char		*ft_expand_word(char *str);
char		*ft_expand_heredoc_data(char *str);
char		*ft_expand_heredoc_eof(char *str);

/*
** =============================================================================
** Tokens Functions
** =============================================================================
*/
int			ft_str_is_double_token(char *str);
int			ft_str_is_special_token(char *str);
int			ft_str_is_command_sep(char *str);
int			ft_str_is_redirect(char *str);
int			ft_str_is_heredoc(char *str);
int			ft_str_is_pipe(char *str);
int			ft_str_is_wildcard(char *str);

int			ft_is_quote(int c);
int			ft_is_heredoc(int c);
int			ft_is_redirect(int c);

char		*ft_find_word_in_list(int code);
int			ft_find_code_in_list(char *word);
int			ft_get_code_word(char *word);

/*
** =============================================================================
** Utils Functions
** =============================================================================
*/
void		*ft_copy_char(void *ptr);
void		*ft_copy_data_from_word(void *ptr);
void		*ft_copy_exportstr_from_var(void *ptr);
void		*ft_copy_declare_from_var(void *ptr);

void		ft_report_error(const char *name, const char *err);
void		ft_perror(const char *str);
void		ft_internal_error(const char *str, const char *err);
void		ft_fatal_error(const char *str, const char *err);
int			ft_failure_error(const char *str);

#endif
