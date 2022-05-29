/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:12:37 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 15:05:44 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# define DIRSEP	'/'

char		*ft_path_join(const char *s1, const char *s2);
char		*ft_get_path(char **env, char *cmd);
char		*ft_get_dir_items(char *name);

int			ft_is_abspath(char *str);
int			ft_is_relpath(char *str);
int			ft_is_dirsep(int c);
int			ft_is_pathsep(int c);
int			ft_absolute_pathname(const char *str);
int			ft_absolute_program(const char *str);
char		*ft_get_work_dir(void);

int			ft_file_exists(const char *file);
int			ft_file_isdir(const char *file);

#endif
