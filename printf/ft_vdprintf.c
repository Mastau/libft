/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:53:10 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/19 13:15:42 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

static int	ft_convert(int fd, const char c, va_list ap)
{
	int	res;

	res = 0;
	if (c == 'c')
		res += ft_putchar_fd((char)va_arg(ap, int), fd);
	else if (c == 's')
		res += ft_putstr_fd(va_arg(ap, char *), fd);
	else if (c == 'p')
		ft_putpointer_fd((unsigned long int)va_arg(ap, void *), fd, &res);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd_c(va_arg(ap, int), fd, &res);
	else if (c == 'u')
		ft_putnbr_base_fd(va_arg(ap, unsigned int), "0123456789", fd, &res);
	else if (c == 'x')
		ft_putnbr_base_fd(va_arg(ap, unsigned int), "0123456789abcdef", fd,
			&res);
	else if (c == 'X')
		ft_putnbr_base_fd(va_arg(ap, unsigned int), "0123456789ABCDEF", fd,
			&res);
	else if (c == '%')
		res += ft_putchar_fd('%', fd);
	return (res);
}

int	ft_vdprintf(int fd, const char *format, ...)
{
	int		res;
	va_list	ap;

	res = 0;
	va_start(ap, format);
	if (!(*format))
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				res += ft_convert(fd, *format, ap);
			else
				return (-1);
		}
		else
			res += write(fd, format, 1);
		format++;
	}
	va_end(ap);
	return (res);
}
