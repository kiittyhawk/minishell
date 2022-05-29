/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:01:45 by llornel           #+#    #+#             */
/*   Updated: 2022/03/21 14:41:00 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct s_data_flag
{
	int		type;
	int		width;
	int		precision;
	int		is_width;
	int		is_precision;
	int		pad_width;
	int		pad_precision;
	int		zero;
	int		percent;
	int		lattice;
	int		space;
	int		sign;
	int		dash;
	int		is_zero;
	int		pos;
	int		fd;
	size_t	retlen;
}		t_data_flag;

int		ft_chk_typeslst(int c);
int		ft_chk_flagslst(int c);
int		ft_chk_dotstar(int c);

void	ft_parse_space(t_data_flag *data_flag);
void	ft_parse_lattice(t_data_flag *data_flag);
void	ft_parse_plus(t_data_flag *data_flag);
void	ft_parse_zero(t_data_flag *data_flag);
void	ft_parse_dash(t_data_flag *data_flag);
void	ft_parse_str(char *str, t_data_flag *data_flag, va_list args);

void	ft_handler_int(t_data_flag *data_flag, va_list args);
void	ft_handler_uint(t_data_flag *data_flag, va_list args);
void	ft_handler_char(t_data_flag *data_flag, va_list args);
void	ft_handler_str(t_data_flag *data_flag, va_list args);
void	ft_handler_ptr(t_data_flag *data_flag, va_list args);
void	ft_handler_hex(t_data_flag *data_flag, va_list args);
void	ft_handler_hexx(t_data_flag *data_flag, va_list args);
void	ft_handler_percent(t_data_flag *data_flag);

void	ft_output_int(t_data_flag *data_flag, char *str);
void	ft_output_uint(t_data_flag *data_flag, char *str);
void	ft_output_char(t_data_flag *data_flag, char c);
void	ft_output_str(t_data_flag *data_flag, char *str);
void	ft_output_ptr(t_data_flag *data_flag, char *str);
void	ft_output_hex(t_data_flag *data_flag, char *str);
void	ft_output_percent(t_data_flag *data_flag, char c);

int		ft_dprintf(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);

#endif
