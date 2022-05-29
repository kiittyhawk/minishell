/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 00:51:38 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 12:17:14 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

void		ft_builtin_error(char *builtin, char *name, char *err);	
int			ft_builtin_failure(char *builtin, char *name);
int			ft_is_builtin(char *str);

int			ft_move_path(t_list *vars, char *path, char *oldpath, bool print);
int			ft_check_var(char *name, char*path);

int			ft_cd_path(t_list *vars, char *arg);
int			ft_cd_oldpath(t_list *vars);
int			ft_cd_cdpath(t_list *vars, char *arg, char *cdpath);
int			ft_cd_home(t_list *vars);
int			ft_cd_tilde(t_list *vars, char *arg);

int			ft_do_builtin(char **args, int child);
int			ft_builtin_echo(char **args);
int			ft_builtin_cd(char **args, t_list *vars);
int			ft_builtin_pwd(void);
int			ft_builtin_export(char **args, t_list *vars);
int			ft_builtin_unset(char **args, t_list *vars);
int			ft_builtin_env(t_list *vars);
int			ft_builtin_exit(char **args, int child);

#endif