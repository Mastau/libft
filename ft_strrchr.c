/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:33:58 by thomarna          #+#    #+#             */
/*   Updated: 2024/10/09 11:44:20 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	i = len;
	if (c == 0)
		return (((char *)s) + len);
	while (i > 0)
	{
		if (s[i] == (char)c)
			return (((char *)s + i));
		i--;
	}
	if (s[0] == (char)c)
		return (((char *)s));
	return (NULL);
}
