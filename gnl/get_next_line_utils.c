/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:20:18 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/04 18:41:34 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char	*ft_realloc(char *str, size_t len)
{
	char	*ptr;

	if (len == 0)
	{
		free(str);
		return (NULL);
	}
	if (str == NULL)
		return (malloc(sizeof(char) * len));
	ptr = malloc(len * sizeof(char));
	if (ptr)
	{
		ft_strcpy(ptr, str);
		free(str);
	}
	return (ptr);
}
