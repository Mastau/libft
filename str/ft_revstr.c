/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:32:24 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/22 17:19:35 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstr(char *str)
{
	int		i;
	int		size;
	char	c;

	i = 0;
	size = ft_strlen(str);
	while (i < size / 2)
	{
		c = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = c;
		i++;
	}
	return (str);
}
