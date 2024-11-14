/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinsep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:58:02 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/14 16:01:11 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinsep(int size, char **strs, char *sep)
{
	int		len;
	int		i;
	int		j;
	char	*dest;

	j = 0;
	len = ft_strlentab(size, strs);
	len += ft_strlen(sep) * len;
	dest = malloc(len * sizeof(char));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		len = 0;
		while (len < (int)ft_strlen(strs[i]))
			dest[j++] = strs[i][len++];
		len = 0;
		while (sep[len] && i != size - 1)
			dest[j++] = sep[len++];
	}
	dest[j] = '\0';
	return (dest);
}
