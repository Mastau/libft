/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:13:37 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/04 19:17:11 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putnbr_fd_c(int nb, int fd, int *count)
{
	if (nb == -2147483648)
	{
		*count += ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (nb < 0)
	{
		*count += ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb < 10)
		*count += ft_putchar_fd(nb + '0', fd);
	else
	{
		ft_putnbr_fd_c(nb / 10, fd, count);
		*count += ft_putchar_fd(nb % 10 + '0', fd);
	}
}

void	ft_putnbr_base_fd(unsigned long int nb, char *base, int fd, int *count)
{
	unsigned long int	base_size;

	if (!base || !fd || !count)
		return ;
	base_size = ft_strlen(base);
	if (nb >= base_size)
	{
		ft_putnbr_base_fd(nb / base_size, base, fd, count);
		*count += ft_putchar_fd(base[nb % base_size], fd);
	}
	else
		*count += ft_putchar_fd(base[nb], fd);
}

void	ft_putpointer_fd(unsigned long int ptr, int fd, int *count)
{
	if (!ptr)
		*count += ft_putstr_fd("(nil)", fd);
	else
	{
		*count += ft_putstr_fd("0x", fd);
		ft_putnbr_base_fd(ptr, "0123456789abcdef", fd, count);
	}
}
