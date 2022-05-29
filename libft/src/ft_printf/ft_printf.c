/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:00:26 by llornel           #+#    #+#             */
/*   Updated: 2022/03/21 14:40:16 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data_flag	*ft_init_data_flag(t_data_flag *data_flag, int fd)
{
	data_flag->type = 0;
	data_flag->pos = -1;
	data_flag->width = 0;
	data_flag->precision = 0;
	data_flag->is_width = 0;
	data_flag->is_precision = 0;
	data_flag->pad_width = 0;
	data_flag->pad_precision = 0;
	data_flag->zero = 0;
	data_flag->dash = 0;
	data_flag->lattice = 0;
	data_flag->percent = 0;
	data_flag->space = 0;
	data_flag->sign = 0;
	data_flag->is_zero = 0;
	data_flag->retlen = 0;
	data_flag->fd = fd;
	return (data_flag);
}

static int	ft_print_str(int fd, char *str, va_list args)
{
	t_data_flag	*data_flag;
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	data_flag = (t_data_flag *)malloc(sizeof(t_data_flag));
	if (data_flag == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] != '%')
			ret += ft_putchar_fd(fd, str[i]);
		else if (str[i] == '%' && str[i + 1])
		{
			ft_init_data_flag(data_flag, fd);
			data_flag->pos = i + 1;
			ft_parse_str(str, data_flag, args);
			ret += data_flag->retlen;
			i = data_flag->pos++;
		}
		i++;
	}
	free(data_flag);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	const char	*str;
	size_t		ret;

	if (format == NULL)
		return (0);
	str = ft_strdup(format);
	if (str == NULL)
		return (-1);
	ret = 0;
	va_start(args, format);
	ret = ft_print_str(STDOUT, (char *)str, args);
	va_end(args);
	free((char *)str);
	return (ret);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list		args;
	const char	*str;
	size_t		ret;

	if (fd < 0 || format == NULL)
		return (0);
	str = ft_strdup(format);
	if (str == NULL)
		return (-1);
	ret = 0;
	va_start(args, format);
	ret = ft_print_str(fd, (char *)str, args);
	va_end(args);
	free((char *)str);
	return (ret);
}
