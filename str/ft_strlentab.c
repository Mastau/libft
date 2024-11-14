/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlentab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:55:58 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/14 15:57:06 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlentab(int size, char **strs)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (size == 0)
	{
		return (1);
	}
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	return (len);
}
