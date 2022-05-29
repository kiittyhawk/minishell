/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:29:00 by llornel           #+#    #+#             */
/*   Updated: 2022/03/20 22:20:59 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_H
# define VAR_H

# define VAR_EXPORT 			1
# define VAR_READONLY			2
# define VAR_INVISIBLE			3

int			ft_is_name_char(int c);
int			ft_is_name_starter(int c);

int			ft_valid_number(const char *str, long *result);
int			ft_size_name(const char *str);
int			ft_valid_name(const char *name);
int			ft_valid_assignment(const char *str);

t_var		*ft_var_find(t_list *lst, char *name);
void		ft_var_remove(t_list *lst, char *name);
char		*ft_var_get(t_list *lst, char *name);
char		*ft_var_get_value(t_var *var);
int			ft_var_set(t_list *lst, char *name, char *value, int attributes);
int			ft_var_set_export(t_list *lst, char *name, char *value);

char		*ft_var_exportstr(char *name, char *value);
void		ft_var_parse(char *str, char **name, char **value);
int			ft_var_lstadd(t_list **vars, char *str, int attributes);
int			ft_vars_init(t_list **vars, char **envp);

#endif
