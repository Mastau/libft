/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:21:01 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/19 14:11:24 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putnbr_base_fd(unsigned long int nb, char *base, int fd, int *count);
void	ft_putnbr_fd_c(int nb, int fd, int *count);
void	ft_putpointer_fd(unsigned long int ptr, int fd, int *count);
int		ft_vdprintf(int fd, const char *format, va_list ap);
int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);

#endif
