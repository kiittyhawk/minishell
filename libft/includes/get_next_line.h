/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:22:29 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 10:09:32 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_listfd
{
	int				fd;
	char			*data;
	struct s_listfd	*next;
}				t_listfd;

void		ft_listfreeone(t_listfd *lst);
void		ft_listdelone(t_listfd **lst, t_listfd *del);
t_listfd	*ft_listnew(int fd);
t_listfd	*ft_listadd(t_listfd **lst, int fd);

int			get_next_line(int fd, char **line);

#endif